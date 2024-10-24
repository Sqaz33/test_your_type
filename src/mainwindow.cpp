#include "include/mainwindow.hpp"

#include <string>

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTextEdit>
#include <QTextCharFormat>
#include <QWidget>
#include <iostream>

#include "include/utils.hpp"

#define DEBUG

namespace mainwindow {

MainWindow::MainWindow(QWidget* parrent) :
    QMainWindow(parrent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();

}

MainWindow::~MainWindow() {}


// ########################################################
// ########################################################
// ########################################################
// ########################################################


void MainWindow::setupConnections() {
    connect(ui->openText_btn, &QPushButton::clicked, this, &MainWindow::loadTextNPutOnEditTextWidget);

    connect(ui->textEdit, &QTextEdit::textChanged, this, &MainWindow::textEditWidgetInputTextHandler);

    connect(ui->textEdit, &QTextEdit::cursorPositionChanged, this, &MainWindow::setTextEditCursorOnCurCheckedPos);
}

void MainWindow::loadTextNPutOnEditTextWidget() {
    // 1
    auto fName = getFileNameViaFileDialog();
    if (!fName.length()) {
        return;
    }

    std::string text;
    utils::loadText(fName.c_str(), text);

    // 2
    ui->textEdit->setText(QString::fromStdString(text));
    curCheckedPos = 0;
    strComp.clear();
    pre = QString::fromStdString(text);
    strComp.setSrc(pre);
    setTextEditCursorOnCurCheckedPos();
}

std::string MainWindow::getFileNameViaFileDialog() {
    auto fileName = 
        QFileDialog::getOpenFileName(this, "Select a file", "", "Text Files (*.txt)");
    return fileName.toStdString();
}

void MainWindow::textEditWidgetInputTextHandler() {
    static bool f = false;
    if (f) {
        return;
    }
    if (!strComp.src().length()) {
        return;
    }
    auto text = ui->textEdit->toPlainText();
    if (text.length() < pre.length()) {
        f = true;
        std::cout << "eblan?\n";
        ui->textEdit->setText(pre);
        return; 
    }
    bool ok = strComp.pushLetter(text[curCheckedPos++]);

    auto cursor = ui->textEdit->textCursor();
    cursor.setPosition(curCheckedPos - 1);
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, 1);
    f = true;
    cursor.removeSelectedText();

    cursor.setPosition(curCheckedPos - 1);
    cursor.movePosition(QTextCursor::Right, QTextCursor::KeepAnchor, 1);
    QTextCharFormat format;
    format.setForeground(ok ? Qt::green : Qt::red);  
    cursor.setCharFormat(format);
    f = false;
}

void MainWindow::setTextEditCursorOnCurCheckedPos() {
    auto cursor = ui->textEdit->textCursor();
    cursor.setPosition(curCheckedPos);
    ui->textEdit->setTextCursor(cursor);
}

} // namespace mainwindow

