#include "steganography.h"
#include "ui_steganography.h"
#include <QFileDialog>
#include <QMessageBox>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <bitset>
using namespace std;
QString datain, wavin;
string dataFile, wavFile;
steganography::steganography(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::steganography)
{
    ui->setupUi(this);
}

steganography::~steganography()
{
    delete ui;
}

void steganography::on_openData_clicked()
{
    datain=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","Allfiles(*)");
    dataFile = datain.toStdString();
}

void steganography::on_openWav_clicked()
{
    wavin=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","wav (*.wav);;");
    wavFile = wavin.toStdString();
}

void steganography::on_encodeButton_clicked()
{
    string wav = "WAVE";
    string tmp = "";
    tmp.reserve(4);

    vector<unsigned char> wavBytes;
    ifstream wavin(wavFile.c_str());
    wavin.seekg(0, ios::end);

    size_t len1 = wavin.tellg();
    char *ret1 = new char[len1];
    wavin.seekg(0, ios::beg);
    wavin.read(ret1, len1);
    wavin.close();

    for (size_t i = 0; i < len1; i++)
    {
        wavBytes.push_back(static_cast<unsigned char>(ret1[i]));
    }

    vector<unsigned char> dataBytes;
    ifstream datain(dataFile.c_str());
    datain.seekg(0, ios::end);

    size_t len2 = datain.tellg();
    char *ret2 = new char[len2];
    datain.seekg(0, ios::beg);
    datain.read(ret2, len2);
    datain.close();

    for (size_t i = 0; i < len2; i++)
    {
        dataBytes.push_back(static_cast<unsigned char>(ret2[i]));
    }

    for (int i = 8; i < 12; i++)
    {
        tmp += wavBytes[i];
    }
    if (tmp != wav)
    {
        QMessageBox::information(this,tr("Ошибка"),tr("Это не WAV файл! Нас не обманешь!"));
    }
    if (wavBytes.size() - 44 < dataBytes.size() * 8)
    {
       QMessageBox::information(this,tr("Ошибка"),tr("WAV файл слишком маленький!"));
    }

    size_t j = 44;
    for (size_t i = 0; i < dataBytes.size(); i++)
    {
        bitset<8> txtByte(dataBytes[i]);

        for (long long k = txtByte.size() - 1; k > -1 ; k--)
        {
            bitset<8> wavByte(wavBytes[j]);
            wavByte[0] = txtByte[k];

            unsigned long tmp = wavByte.to_ulong();
            wavBytes[j] = static_cast<unsigned char>(tmp);

            ++j;
        }

    }
    //QString o = ui->outputEdit->text();
    //string output = o.toStdString();
    QString o=QFileDialog::getSaveFileName(this,tr("Открыть файл"),"/Users/","Allfiles(*.wav)");
    string output = o.toStdString();
    ofstream outp(output.c_str());
    for (size_t i = 0; i < wavBytes.size(); i++)
    {
        outp << wavBytes[i];
    }
    outp.close();
}

