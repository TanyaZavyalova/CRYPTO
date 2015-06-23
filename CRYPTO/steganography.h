#ifndef STEGANOGRAPHY_H
#define STEGANOGRAPHY_H

#include <QMainWindow>

namespace Ui {
class steganography;
}

class steganography : public QMainWindow
{
    Q_OBJECT

public:
    explicit steganography(QWidget *parent = 0);
    ~steganography();

private slots:
    void on_openData_clicked();

    void on_openWav_clicked();

    void on_encodeButton_clicked();

private:
    Ui::steganography *ui;
};

#endif // STEGANOGRAPHY_H
