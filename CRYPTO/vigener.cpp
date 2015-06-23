#include "vigener.h"
#include "ui_vigener.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>
#include <QFileDialog>
#include <QMessageBox>
using namespace std;
QString vinfile, voutfile;
string voutput, vinput;
string vs, vsout;
vigener::vigener(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vigener)
{
    ui->setupUi(this);
}

vigener::~vigener()
{
    delete ui;
}

void vigener::on_encodeButton_clicked()
{
    int *mas = NULL;
    voutput = voutfile.toStdString();
    string snew;
    QString keyE = ui->keyEdit->text();
    string key = keyE.toStdString();
    int slen = vs.length();
    int klen = key.length();
    string keynew = "";
            if (slen > klen)
            {
                for (int i = 0; i < (slen / klen); i++)
                {
                    keynew = keynew + key;
                }
                for (int j = 0; j < (slen %klen); j++)
                {
                    keynew = keynew + key[j];
                }
            }
            else
            {
                for (int i = 0; i < slen; i++)
                {
                    keynew = keynew + key[i];
                }
            }
            mas = new int[slen];
            for (int x = 0; x < slen; x++)
            {
                keynew[x] = toupper(keynew[x]);
                mas[x] = keynew[x] - 65;
            }
    for (int x = 0; x < slen; x++)
    {
        if (isalpha(vs[x]))
            {
                vs[x] = toupper(vs[x]);
                snew +=(((vs[x] - 65) + mas[x]) % 26) + 65;
            }
    }
    ui->dataOutput->setText(QString::fromStdString(snew));
    ofstream out(voutput.c_str());
    out<<snew;
    out.close();
    snew.clear();
}

void vigener::on_decodeButton_clicked()
{
    int *mas = NULL;
    voutput = voutfile.toStdString();
    string snew;
    QString keyE = ui->keyEdit->text();
    string key = keyE.toStdString();
    int slen = vs.length();
    int klen = key.length();
    string keynew = "";
            if (slen > klen)
            {
                for (int i = 0; i < (slen / klen); i++)
                {
                    keynew = keynew + key;
                }
                for (int j = 0; j < (slen %klen); j++)
                {
                    keynew = keynew + key[j];
                }
            }
            else
            {
                for (int i = 0; i < slen; i++)
                {
                    keynew = keynew + key[i];
                }
            }
            mas = new int[slen];
            for (int x = 0; x < slen; x++)
            {
                keynew[x] = toupper(keynew[x]);
                mas[x] = keynew[x] - 65;
            }
    for (int x = 0; x < slen; x++)
    {
        if (isalpha(vs[x]))
            {
                vs[x] = toupper(vs[x]);
                snew += (((vs[x] - 65) - mas[x]) % 26) + 65;
            }
    }
    ui->dataOutput->setText(QString::fromStdString(snew));
    ofstream out(voutput.c_str());
    out<<snew;
    out.close();
    snew.clear();
}



void vigener::on_openInput_clicked()
{
    vinfile=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","Allfiles(*)");
    vinput = vinfile.toStdString();
    ifstream in(vinput.c_str());
    getline(in,vs);
    in.close();
    ui->dataInput->setText(QString::fromStdString(vs));
}

void vigener::on_openOutput_clicked()
{
    voutfile=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","Allfiles (*)");
    voutput = voutfile.toStdString();
    ifstream out(voutput.c_str());
    getline(out,vsout);
    out.close();
    ui->dataOutput->setText(QString::fromStdString(vsout));
}
