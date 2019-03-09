#pragma once
#include <QStringList>
#include <QString>
#include <QObject>
#include <tins/tins.h>

class PacketObject : public QObject {
	Q_OBJECT
public:
	PacketObject(bool, QString, QString, std::unique_ptr<Tins::RawPDU>);

	PacketObject(const Tins::PDU&);

	bool isIncoming() const noexcept;

	QString& getAddress();
	QString& getPacketData();
	Tins::RawPDU* getRawData() const noexcept;

private:
	bool incoming;
	QString address;
	QString packetData;
	std::unique_ptr<Tins::RawPDU> rawPDU;
};