#include "TogetherPE.h"
#include "packetLogger.h"

#include <iostream>
#include <tins/tins.h>

#include <QStandardItemModel>
#include <QTableView>
#include <QTimer>

#include "pybind11/pybind11.h"

#include <Packet.h>

using namespace Tins;

TogetherPE::TogetherPE(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(this, &TogetherPE::closeEvent, this, [this]() { stopPackets(); sniffingThread->wait(); packetSniffer->wait(); qApp->quit(); });
}

void TogetherPE::log(std::string s) {
	this->log(QString::fromStdString(s));
}

void TogetherPE::startLogging() {
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
}
void TogetherPE::stopPackets() {
	packetSniffer->getSniffer()->stop_sniff();
	packetSniffer->requestInterruption();
	sniffingThread->requestInterruption();
	packetSniffer->terminate();
	sniffingThread->terminate();
}

void TogetherPE::logText(const QString& s) {
	log(s);
}

void TogetherPE::incomingPacket(PacketObject* p) {
	QList<QStandardItem *> items = {
		new QStandardItem(p->getAddress()),
		new QStandardItem(p->getPacketData())
	};

	for (int i = 0; i < items.size(); i++) {
		if (p->isIncoming()) items[i]->setForeground(QColor::fromRgb(255, 0, 0));
		else items[i]->setForeground(QColor::fromRgb(0, 0, 255));
	}
	tableModel->appendRow(items);
}

void TogetherPE::resizeEvent(QResizeEvent* event) {
	QMainWindow::resizeEvent(event);
}
