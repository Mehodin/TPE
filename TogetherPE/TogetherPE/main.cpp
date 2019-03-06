#include "TogetherPE.h"
#include <QtWidgets/QApplication>
#include "packetLogger.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TogetherPE w;
	w.show();
	return a.exec();
}
