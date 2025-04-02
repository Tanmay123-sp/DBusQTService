#include <QApplication>
#include "dbusservice.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    dbusService service;
    return app.exec();
}
