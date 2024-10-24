/**
 * @file mainwindow.hpp
 * @brief This file contains the declaration of the MainWindow class.
 * 
 * @author Matveev S.A. email: mset321@gmail.com
 */

#ifndef SRC_INCLUDE_MAINWINDOW_HPP
#define SRC_INCLUDE_MAINWINDOW_HPP

#include <memory>
#include <string>

#include <QFileDialog>
#include <QMainWindow>
#include <QString>
#include <QWidget>

#include "ui_mainwindow.h"

#include "incremental_string_comparer.hpp"


namespace mainwindow {

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parrent = nullptr);
    
    ~MainWindow();
    
private:
    void setupConnections();
    std::string getFileNameViaFileDialog();

private slots:
    void loadTextNPutOnEditTextWidget();
    void textEditWidgetInputTextHandler();
    void setTextEditCursorOnCurCheckedPos();

protected:
    int curCheckedPos = 0;
    QString pre;
    std::unique_ptr<Ui::MainWindow> ui;

    incremental_string_comparer::IncrementalStringComparer<QString> strComp;
};

} // namespace mainwindow

#endif
