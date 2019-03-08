#include <TogetherPE.h>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <thread>

#include "packetLogger.h"
#include "Packet.h"


PacketLogger::PacketLogger(TogetherPE* t) {
	this->t = t;
	connect(t, &TogetherPE::stopSniffing, this, &PacketLogger::stopLogging);
}

void PacketLogger::process() {
	auto controller = NetworkInterface::default_interface();
	try {
		emit attemptLog(QString::fromStdString("Attempting to connect to " + controller.name() + " -> ") + QString::fromStdWString(controller.friendly_name()));
		snf = std::make_unique<Sniffer>(controller.name());
		snf->sniff_loop([this](const PDU& pdu) {
			return logPacket(pdu);
		});
		emit attemptLog(QString::fromStdString("Connected to " + controller.name() + " -> ") + QString::fromStdWString(controller.friendly_name()));
	}
	catch (std::exception& e) {
		emit attemptLog("Failed to capture packet");
	}
	return;
}

void PacketLogger::stopLogging() {
	snf->stop_sniff();
}

bool PacketLogger::logPacket(const PDU& pdu) {
	auto currentColumn = columnCount;
	auto* p = PacketObject::fromRawPdu(pdu);
	if (!t->ui.customFilterCheckbox->isChecked()) {
		if (p->isIncoming() && !t->ui.incomingCheckbox->isChecked()) {
			return true;
		}
		if (!p->isIncoming() && !t->ui.outgoingCheckbox->isChecked()) {
			return true;
		}
		if (t->ui.ipCheckbox->isChecked()) {
			if (!p->getAddress().startsWith(t->ui.ipLineEdit->text())) return true;
		}
		if (t->ui.portCheckbox->isChecked()) {
			if (!p->getAddress().endsWith(t->ui.portLineEdit->text())) return true;
		}
		if (t->ui.minimumSizeCheckbox->isChecked()) {
			if (t->ui.minimumSizeSpinbox->value() > p->getRawData()->header_size()) return true;
		}
		if (t->ui.maximumSizeCheckbox->isChecked()) {
			if (t->ui.maximumSizeSpinbox->value() < p->getRawData()->header_size()) return true;
		}
	}
	else {
		if (parseFilterString(p)) return true;
	}
	emit incomingPacket(p);
	return true;
}

Sniffer* PacketLogger::getSniffer() {
	return std::move(snf.get());
}

bool PacketLogger::parseFilterString(PacketObject* p) {
	//outgoing(=1) incoming(=1) ip(=104.16.59.37) port(=80,8080,59) size(=0,99999)
	auto& filterText = t->ui.customFilterEdit->toPlainText();
	QRegExp outgoingRegex{ R"(outgoing\(=(.*)\))", Qt::CaseInsensitive };
	outgoingRegex.setMinimal(true);
	outgoingRegex.lastIndexIn(filterText);
	QRegExp incomingRegex{ R"(incoming\(=(.*)\))", Qt::CaseInsensitive };
	incomingRegex.setMinimal(true);
	incomingRegex.indexIn(filterText);
	QRegExp ipsRegex{ R"(ip\(=(.*)\))", Qt::CaseInsensitive };
	ipsRegex.setMinimal(true);
	ipsRegex.indexIn(filterText);
	QRegExp portsRegex{ R"(port\(=(.*)\))", Qt::CaseInsensitive };
	portsRegex.setMinimal(true);
	portsRegex.indexIn(filterText);
	QRegExp sizeRegex{ R"(size\(=(.*)\))", Qt::CaseInsensitive };
	sizeRegex.setMinimal(true);
	sizeRegex.indexIn(filterText);

	if (outgoingRegex.captureCount()) {
		if (outgoingRegex.capturedTexts().last() == "0" && !p->isIncoming()) return true;
	}
	if (incomingRegex.captureCount()) {
		if (incomingRegex.capturedTexts().last() == "0" && p->isIncoming()) return true;
	}

	if (ipsRegex.captureCount() && ipsRegex.capturedTexts().last() != "") {
		bool valid = false;
		for (auto& each : ipsRegex.capturedTexts().last().split(',')) {
			if (p->getAddress().startsWith(each)) {
				valid = true;
				break;
			}
		}
		if (!valid) {
			return true;
		}
	}

	if (portsRegex.captureCount() && portsRegex.capturedTexts().last() != "") {
		bool valid = false;
		for (auto& each : portsRegex.capturedTexts().last().split(',')) {
			if (p->getAddress().endsWith(each.trimmed())) {
				valid = true;
				break;
			}
		}
		if (!valid) return true;
	}

	if (sizeRegex.captureCount()) {
		auto splitSize = sizeRegex.capturedTexts().last().split(',');
		if (splitSize.size() == 0) return false;
		if (splitSize.size() < 2) return !(p->getRawData()->payload_size() >= splitSize[0].toInt());
		else return !(p->getRawData()->payload_size() >= splitSize[0].toInt() && p->getRawData()->payload_size() <= splitSize[1].toInt());
	}
	return false;
}