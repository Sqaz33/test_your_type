#include "include/mainwindow.hpp"

#include <QMainWindow>
#include <QWidget>

namespace mainwindow {

MainWindow::MainWindow(QWidget* parrent) :
    QMainWindow(parrent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {}

void MainWindow::setupTextEdit() {
    
}

} // namespace mainwindow