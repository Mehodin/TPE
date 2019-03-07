#include <TogetherPE.h>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <thread>
#include "thread_call.h"

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
	emit incomingPacket(p);
	return true;
}

Sniffer* PacketLogger::getSniffer() {
	return std::move(snf.get());
}