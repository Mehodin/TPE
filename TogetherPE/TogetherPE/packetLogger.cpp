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
}

void PacketLogger::process() {
	auto each = NetworkInterface::default_interface();
	try {
		emit attemptLog(QString::fromStdString("Attempting to connect to " + each.name() + " -> ") + QString::fromStdWString(each.friendly_name()));
		auto snf = Sniffer(each.name());
		snf.sniff_loop([this](const PDU& pdu) {
			return logPacket(pdu);
		});
		emit attemptLog(QString::fromStdString("Connected to " + each.name() + " -> ") + QString::fromStdWString(each.friendly_name()));

	}
	catch (std::exception& e) {
		emit attemptLog("Failed to capture packet");
	}
	return;
}

bool PacketLogger::logPacket(const PDU& pdu) {
	auto currentColumn = columnCount;
	auto* p = PacketObject::fromRawPdu(pdu);
	emit incomingPacket(p);
	return true;
}