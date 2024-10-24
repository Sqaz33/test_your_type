#include <string>
#include <iostream>

#include <QApplication>

#include "include/mainwindow.hpp"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    mainwindow::MainWindow w;
    w.setWindowTitle("Check your type");
    w.resize(300, 300);
    w.show();

    return app.exec();
}   