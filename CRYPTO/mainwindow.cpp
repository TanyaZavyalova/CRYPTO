#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "caesar.h"
#include "vigener.h"
#include "steganography.h"
#include "desint.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        ui->setupUi(this);
    }

MainWindow::~MainWindow()
{
        delete ui;
    }

void MainWindow::on_caesar_triggered()
{
        caesar *cwnd = new caesar(this);
        cwnd->show();
    }



void MainWindow::on_vigener_triggered()
{
        vigener *vwnd = new vigener(this);
        vwnd->show();
    }

void MainWindow::on_steganography_triggered()
{
        steganography *swnd = new steganography(this);
        swnd->show();
    }

void MainWindow::on_DES_triggered()
{
        DESint *dwnd = new DESint(this);
        dwnd->show();
    }
