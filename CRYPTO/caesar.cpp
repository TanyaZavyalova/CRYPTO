#include "caesar.h"
#include "ui_caesar.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
using namespace std;
QString infile, outfile;
string output, input;
string s, sout;
caesar::caesar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::caesar)
{
    ui->setupUi(this);
}

caesar::~caesar()
{
    delete ui;
}

void caesar::on_encodeButton_clicked()
{
    output = outfile.toStdString();
    string snew;
    int sdv = ui->keyBox->value();
    for (unsigned long x = 0; x < s.length(); x++)
    {
        if (isalpha(s[x]))
            {
                s[x] = toupper(s[x]);
                snew += (((s[x] - 65) + sdv) % 26) + 65;
            }
    }
    ui->dataOutput->setText(QString::fromStdString(snew));
    ofstream out(output.c_str());
    out<<snew;
    out.close();
    snew.clear();
}

void caesar::on_decodeButton_clicked()
{
    output = outfile.toStdString();
    string snew;
    int sdv = ui->keyBox->value();
    for (unsigned long x = 0; x < s.length(); x++)
    {
        if (isalpha(s[x]))
            {
                s[x] = toupper(s[x]);
                snew += (((s[x] - 65) - sdv) % 26) + 65;
            }
    }
    ui->dataOutput->setText(QString::fromStdString(snew));
    ofstream out(output.c_str());
    out<<snew;
    out.close();
    snew.clear();
}

void caesar::on_openInput_clicked()
{
    infile=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","Allfiles(*)");
    //QMessageBox::information(this,tr("Имя файла"),infile);
    input = infile.toStdString();
    ifstream in(input.c_str());
    getline(in,s);
    in.close();
    ui->dataInput->setText(QString::fromStdString(s));
}

void caesar::on_openOutput_clicked()
{
    outfile=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","Allfiles (*)");
    //QMessageBox::information(this,tr("Имя файла"),outfile);
    output = outfile.toStdString();
    ifstream out(output.c_str());
    getline(out,sout);
    out.close();
    ui->dataOutput->setText(QString::fromStdString(sout));
}

