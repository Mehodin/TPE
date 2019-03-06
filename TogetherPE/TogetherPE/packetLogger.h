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


signals:
	void attemptLog(const QString);
	void incomingPacket(PacketObject*);

public slots:
	void process();

private:
	TogetherPE* t;
	int columnCount = 0;
};
