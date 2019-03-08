#pragma once
#include <QStringList>
#include <QString>
#include <QObject>
#include <tins/tins.h>

class PacketObject : public QObject {
	Q_OBJECT
public:
	PacketObject(bool, QString, QString, std::unique_ptr<Tins::RawPDU>);

	~PacketObject() = default;
	PacketObject(const PacketObject&) = default;
	PacketObject(PacketObject&&) noexcept = default;
	PacketObject& operator=(const PacketObject&) = default;
	PacketObject& operator=(PacketObject&&) = default;


	static PacketObject* fromRawPdu(const Tins::PDU&);

	bool isIncoming();

	QString getAddress();
	QString getPacketData();
	Tins::RawPDU* getRawData();

private:
	bool incoming;
	QString address;
	QString packetData;
	std::unique_ptr<Tins::RawPDU> rawPDU;
};