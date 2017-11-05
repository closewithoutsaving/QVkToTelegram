#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vbthread.run();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pB_startBot_clicked()
{

}

void MainWindow::on_pB_stopBot_clicked()
{

}
