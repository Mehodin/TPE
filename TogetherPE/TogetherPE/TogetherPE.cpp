#include "TogetherPE.h"
#include "packetLogger.h"

#include <iostream>
#include <tins/tins.h>

#include <QStandardItemModel>
#include <QTableView>
#include <Packet.h>

using namespace Tins;

TogetherPE::TogetherPE(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void TogetherPE::log(std::string s) {
	this->log(QString::fromStdString(s));
}

void TogetherPE::startLogging() {
	QStringList headerTitles = { "Direction", "IP", "Data" };
	ui.packetTable->setColumnCount(headerTitles.size());
	ui.packetTable->setHorizontalHeaderLabels(headerTitles);
	//ui.packetTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
	packetSniffer = new PacketLogger(this);
	sniffingThread = new QThread;
	packetSniffer->moveToThread(sniffingThread);
	connect(sniffingThread, &QThread::started, packetSniffer, &PacketLogger::process);
	connect(packetSniffer, &PacketLogger::attemptLog, this, &TogetherPE::logText);
	connect(packetSniffer, &PacketLogger::incomingPacket, this, &TogetherPE::incomingPacket);
	sniffingThread->start();
}

void TogetherPE::logText(const QString& s) {
	log(s);
}

void TogetherPE::incomingPacket(PacketObject* p) {
	QList<QTableWidgetItem*> items = {
		new QTableWidgetItem(p->isIncoming() ? "<-- IN" : "OUT -->"),
		new QTableWidgetItem(p->getAddress()),
		new QTableWidgetItem(p->getPacketData())
	};

	ui.packetTable->insertRow(ui.packetTable->rowCount());

	for (int i = 0; i < items.size(); i++) {
		ui.packetTable->setItem(ui.packetTable->rowCount() - 1, i, items[i]);
	}
}

void TogetherPE::resizeEvent(QResizeEvent* event) {
	QMainWindow::resizeEvent(event);
	ui.packetTable->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);

}