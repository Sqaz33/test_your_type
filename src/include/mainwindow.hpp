/**
 * @file mainwindow.hpp
 * @brief This file contains the declaration of the MainWindow class.
 * 
 * @author Matveev S.A. email: mset321@gmail.com
 */

#ifndef SRC_INCLUDE_MAINWINDOW_HPP
#define SRC_INCLUDE_MAINWINDOW_HPP

#include <memory>

#include <QMainWindow>
#include <QWidget>

#include "ui_mainwindow.h"

namespace mainwindow {

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget* parrent = nullptr);
    
    ~MainWindow();
    
private:
    void setupTextEdit();

protected:
    std::unique_ptr<Ui::MainWindow> ui;
};

} // namespace mainwindow

#endif