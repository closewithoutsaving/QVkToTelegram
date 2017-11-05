#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "vkbotthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pB_startBot_clicked();

    void on_pB_stopBot_clicked();

private:
    Ui::MainWindow *ui;
    VkBotThread vbthread;
};

#endif // MAINWINDOW_H
