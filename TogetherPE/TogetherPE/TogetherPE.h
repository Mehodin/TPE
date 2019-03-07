#pragma once
#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>
#include <QThread>
#include "ui_TogetherPE.h"

class PacketLogger;
class PacketObject;

class QTimer;

class TogetherPE : public QMainWindow
{
	Q_OBJECT
public:
	TogetherPE(QWidget *parent = Q_NULLPTR);

	template <typename T>
	TogetherPE& operator<<(T&& s) {
		log(s);
		return (*this);
	}

	template <typename T>
	void log(T&& s) {
		ui.logEdit->appendPlainText(std::forward<T>(s));
	}

	void log(const std::string s);
	void stopPackets();

private slots:
	void startLogging();
	void logText(const QString&);
	void incomingPacket(PacketObject* p);

signals:
	void stopSniffing();

private:
	void resizeEvent(QResizeEvent*) override;
	QStandardItemModel* tableModel = new QStandardItemModel;;

private:
	Ui::TogetherPEClass ui;
	PacketLogger* packetSniffer;
	QThread* sniffingThread;
};
