#pragma once
#include <QtWidgets/QWidget>
#include "packetLogger.h"
#include <tins/tins.h>
#include <QThread>

using namespace Tins;


class TogetherPE;
class PacketObject;

class PacketLogger : public QThread {
	Q_OBJECT

public:
	PacketLogger(TogetherPE*);
	bool logPacket(const PDU&);
	Sniffer* getSniffer();


signals:
	void attemptLog(const QString);
	void incomingPacket(PacketObject*);

public slots:
	void process();
	void stopLogging();

private:
	std::unique_ptr<Sniffer> snf = nullptr;
	TogetherPE* t;
	int columnCount = 0;
};
