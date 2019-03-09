#pragma once
#include <QtWidgets/QWidget>
#include "packetLogger.h"
#include <tins/tins.h>
#include <QThread>



class TogetherPE;
class PacketObject;

class QRegeExp;
class QString;

class PacketLogger : public QThread {
	Q_OBJECT

public:
	PacketLogger(TogetherPE*);
	bool logPacket(const Tins::PDU&);
	bool parseFilterString(PacketObject*);
	Tins::Sniffer* getSniffer();
	QRegExp getRegex(const QString&);


signals:
	void attemptLog(const QString);
	void incomingPacket(PacketObject*);

public slots:
	void process();
	void stopLogging();

private:
	std::unique_ptr<Tins::Sniffer> snf = nullptr;
	TogetherPE* t;
	int columnCount = 0;
};
