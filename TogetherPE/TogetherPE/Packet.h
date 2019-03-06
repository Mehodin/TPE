#pragma once
#include <QStringList>
#include <QString>
#include <QObject>
#include <tins/tins.h>

class PacketObject : public QObject {
	Q_OBJECT
public:
	PacketObject(bool, QString, QString);

	static PacketObject* fromRawPdu(const Tins::PDU&);

	bool isIncoming();

	QString getAddress();
	QString getPacketData();

private:
	bool incoming;
	QString address;
	QString packetData;
};