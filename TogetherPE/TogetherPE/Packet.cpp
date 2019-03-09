#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "Packet.h"


PacketObject::PacketObject(bool incoming, QString ip, QString data, std::unique_ptr<Tins::RawPDU> rawPDU)
	: incoming{ incoming }, address{ std::move(ip) }, packetData{ std::move(data.toUpper()) }, rawPDU{ std::move(rawPDU) }
{}

PacketObject::PacketObject(const Tins::PDU& pdu)
{
	const Tins::IP& ip = pdu.rfind_pdu<Tins::IP>();
	const Tins::TCP& tcp = pdu.rfind_pdu<Tins::TCP>();
	const Tins::RawPDU& raw = tcp.rfind_pdu<Tins::RawPDU>();
	incoming = ip.src_addr() != Tins::NetworkInterface::default_interface().addresses().ip_addr;
	address = incoming ? QString::fromStdString(ip.src_addr().to_string() + ":" + std::to_string(tcp.sport())) : QString::fromStdString(ip.dst_addr().to_string() + ":" + std::to_string(tcp.dport()));
	std::stringstream data;
	for (auto each : raw.payload()) {
		data << std::setfill('0') << std::setw(2) << std::hex << static_cast<int>(each) << " ";
	}
	packetData = QString::fromStdString(data.str()).toUpper();
	rawPDU = std::make_unique<Tins::RawPDU>(raw);
}

bool PacketObject::isIncoming() const noexcept {
	return incoming;
}

QString& PacketObject::getAddress() {
	return address;
}

QString& PacketObject::getPacketData() {
	return packetData;
}

Tins::RawPDU* PacketObject::getRawData() const noexcept { //KHeartz: const & noexcept
	return rawPDU.get();
}