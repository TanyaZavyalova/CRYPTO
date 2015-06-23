#include "desint.h"
#include "ui_desint.h"
#include <QFileDialog>
#include <QMessageBox>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <streambuf>
#include "descoder.h"
using namespace std;
QString ddatain, keyin;
string ddataFile, keyFile;
DESint::DESint(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DESint)
{
    ui->setupUi(this);
}

DESint::~DESint()
{
    delete ui;
}

void DESint::on_openDataDES_clicked()
{
    ddatain=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","Allfiles(*)");
    ddataFile = ddatain.toStdString();
}

void DESint::on_openKeyDES_clicked()
{
    keyin=QFileDialog::getOpenFileName(this,tr("Открыть файл"),"/Users/","key (*)");
    keyFile = keyin.toStdString();
}

void DESint::on_encodeButtonDES_clicked()
{

    ifstream ddatain(ddataFile.c_str(),ios::binary);
    vector<unsigned char> buffer((std::istreambuf_iterator<char>(ddatain)), (std::istreambuf_iterator<char>()));
    vector<unsigned char> inputDes = buffer;


    ifstream keyin(keyFile.c_str(),ios::binary);
    vector<unsigned char> buffer2((std::istreambuf_iterator<char>(keyin)), (std::istreambuf_iterator<char>()));
    vector<unsigned char> inputKey = buffer2;
    buffer.clear();
    buffer2.clear();
    int oooo=inputKey.size();
    if (oooo != 8)
    {
        QMessageBox::information(this,tr("Ошибка"),tr("Ключ должен быть из 8байт!"));
    }
    DESCoder des(inputKey);
    vector<vector <unsigned char> > input;
    vector<vector <unsigned char> > output;

    while (inputDes.size() % 8 != 0)
    {
        inputDes.push_back(0x00);
    }

    int j = 0;
    for (size_t i = 0; i < inputDes.size() / 8; i++)
    {
        vector<unsigned char> tmp;
        for (size_t i = 0; i < 8; i++)
        {
            tmp.push_back(inputDes[j]);
            ++j;
        }
        input.push_back(tmp);
    }
    for (size_t i = 0; i < input.size(); i++)
         {
             output.push_back(des.encode(input[i]));
         }

    vector<unsigned char> outputDes;

    for (size_t i = 0; i < output.size(); i++)
    {
        for (size_t j = 0; j < output[i].size(); j++)
        {
            outputDes.push_back(output[i][j]);
        }
    }

    QString o=QFileDialog::getSaveFileName(this,tr("Открыть файл"),"/Users/","Allfiles(*)");
    string out = o.toStdString();
    ofstream outp(out.c_str(),ios::binary);
    for (size_t i = 0; i < outputDes.size(); i++)
    {
        outp << static_cast<unsigned char>(outputDes[i]);
    }
    outp.close();
    input.clear();
    output.clear();
    outputDes.clear();
    inputDes.clear();
    inputKey.clear();
}

void DESint::on_decodeButtonDES_clicked()
{
    ifstream ddatain(ddataFile.c_str(),ios::binary);
    vector<unsigned char> buffer((std::istreambuf_iterator<char>(ddatain)), (std::istreambuf_iterator<char>()));
    vector<unsigned char> inputDes = buffer;


    ifstream keyin(keyFile.c_str(),ios::binary);
    vector<unsigned char> buffer2((std::istreambuf_iterator<char>(keyin)), (std::istreambuf_iterator<char>()));
    vector<unsigned char> inputKey = buffer2;
    buffer.clear();
    buffer2.clear();
    int oooo=inputKey.size();
    if (oooo != 8)
    {
        QMessageBox::information(this,tr("Ошибка"),tr("Ключ должен быть из 8байт!"));
    }
    DESCoder des(inputKey);
    vector<vector <unsigned char> > input;
    vector<vector <unsigned char> > output;

    while (inputDes.size() % 8 != 0)
    {
        inputDes.push_back(0x00);
    }

    int j = 0;
    for (size_t i = 0; i < inputDes.size() / 8; i++)
    {
        vector<unsigned char> tmp;
        for (size_t i = 0; i < 8; i++)
        {
            tmp.push_back(inputDes[j]);
            ++j;
        }
        input.push_back(tmp);
    }
    for (size_t i = 0; i < input.size(); i++)
         {
             output.push_back(des.decode(input[i]));
         }
    vector<unsigned char> outputDes;

    for (size_t i = 0; i < output.size(); i++)
    {
        for (size_t j = 0; j < output[i].size(); j++)
        {
            outputDes.push_back(output[i][j]);
        }
    }

    QString o=QFileDialog::getSaveFileName(this,tr("Открыть файл"),"/Users/","Allfiles(*)");
    string out = o.toStdString();
    ofstream outp(out.c_str(),ios::binary);
    for (size_t i = 0; i < outputDes.size(); i++)
    {
        outp << static_cast<unsigned char>(outputDes[i]);
    }
    outp.close();
    input.clear();
    output.clear();
    outputDes.clear();
    inputDes.clear();
    inputKey.clear();
}

