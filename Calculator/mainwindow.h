#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "calculator.h"

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLineEdit *display;
    QPushButton *buttons[16];

private slots:
    void onButtonClicked();
};
#endif // MAINWINDOW_H
