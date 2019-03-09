#include "TogetherPE.h"
#include "packetLogger.h"

#include <iostream>
#include <ctime>
#include <tins/tins.h>

#include <QStandardItemModel>
#include <QTableView>
#include <QTimer>

#include <Packet.h>

using namespace Tins;

TogetherPE::TogetherPE(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(this, &TogetherPE::closeEvent, this, [this]() { stopPackets(); sniffingThread->wait(); packetSniffer->wait(); qApp->quit(); });
}

void TogetherPE::log(const std::string& s) {
	this->log(QString::fromStdString(s));
}

void TogetherPE::startLogging() {
	if (running) {
		log("Already running");
		return;
	}
	QStringList headerTitles = { "IP", "Data" };
	tableModel->clear();
	tableModel->setHorizontalHeaderLabels(headerTitles);
	ui.packetTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	ui.packetTable->setModel(tableModel);
	packetSniffer = new PacketLogger(this);
	sniffingThread = new QThread(this);
	packetSniffer->moveToThread(sniffingThread);
	connect(sniffingThread, &QThread::started, packetSniffer, &PacketLogger::process);
	connect(packetSniffer, &PacketLogger::attemptLog, this, &TogetherPE::logText);
	connect(packetSniffer, &PacketLogger::incomingPacket, this, &TogetherPE::incomingPacket);
	connect(ui.stopButton, &QPushButton::clicked, this, &TogetherPE::stopPackets);
	ui.packetTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	sniffingThread->start();
	running = true;
}
void TogetherPE::stopPackets() {
	packetSniffer->getSniffer()->stop_sniff();
	packetSniffer->requestInterruption();
	sniffingThread->requestInterruption();
	packetSniffer->terminate();
	sniffingThread->terminate();
	running = false;
}

void TogetherPE::logText(const QString& s) {
	log(s);
}

void TogetherPE::incomingPacket(PacketObject* p) {
	QList<QStandardItem *> items = {
		new QStandardItem(p->getAddress()),
		new QStandardItem(p->getPacketData())
	};
	p->getPacketData();

	QColor color;
	for (auto* item : items) {
		if (p->isIncoming()) color = QColor::fromRgb(255, 0, 0);
		else color = QColor::fromRgb(0, 0, 255);
		item->setForeground(color);
	}
	tableModel->appendRow(items);
}

void TogetherPE::resizeEvent(QResizeEvent* event) {
	QMainWindow::resizeEvent(event);
}


std::string TogetherPE::getDateTimeFormatted() {
	time_t     now = time(0);
	struct tm  tstruct = *localtime(&now);
	char       buf[80];
	strftime(buf, sizeof(buf), "[%Y-%m-%d %X] ", &tstruct);
	return std::string(buf);
}