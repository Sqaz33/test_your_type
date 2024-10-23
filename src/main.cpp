#include <string>
#include <iostream>

#include <QApplication>

#include "include/mainwindow.hpp"
#include "include/text_load.hpp"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    mainwindow::MainWindow w;
    w.setWindowTitle("Check your type");
    w.show();

    return app.exec();
    // std::string text;
    // text_loader::loadText("D:/test_your_type/test.txt", text);
    // std::cout << text;
}   