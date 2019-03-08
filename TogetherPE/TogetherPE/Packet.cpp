#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "Packet.h"


PacketObject::PacketObject(bool incoming, QString ip, QString data, std::unique_ptr<Tins::RawPDU> rawPDU) {
	this->incoming = incoming;
	this->address = ip;
	this->packetData = data;
	this->rawPDU = std::move(rawPDU);
}

PacketObject* PacketObject::fromRawPdu(const Tins::PDU& pdu) {
	const Tins::IP& ip = pdu.rfind_pdu<Tins::IP>();
	const Tins::TCP& tcp = pdu.rfind_pdu<Tins::TCP>();
	const Tins::RawPDU& raw = tcp.rfind_pdu<Tins::RawPDU>();
	const bool inc = ip.src_addr() != Tins::NetworkInterface::default_interface().addresses().ip_addr;
	const QString ipAddress = inc ? QString::fromStdString(ip.src_addr().to_string() + ":" + std::to_string(tcp.sport())) : QString::fromStdString(ip.dst_addr().to_string() + ":" + std::to_string(tcp.dport()));
	std::stringstream packetData;
	for (auto each : raw.payload()) {
		packetData << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(each) << " ";
	}
	return new PacketObject{ inc, ipAddress, packetData.str().c_str(), std::make_unique<Tins::RawPDU>(raw) };
}

bool PacketObject::isIncoming() {
	return incoming;
}

QString PacketObject::getAddress() {
	return address;
}

QString PacketObject::getPacketData() {
	return packetData.toUpper();
}

Tins::RawPDU* PacketObject::getRawData() {
	return rawPDU.get();
}