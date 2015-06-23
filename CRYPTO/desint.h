#ifndef DESINT_H
#define DESINT_H

#include <QMainWindow>
#include "descoder.h"
namespace Ui {
class DESint;
}

class DESint : public QMainWindow
{
    Q_OBJECT

public:
    explicit DESint(QWidget *parent = 0);
    ~DESint();

private slots:
    void on_openDataDES_clicked();

    void on_openKeyDES_clicked();

    void on_encodeButtonDES_clicked();

    void on_decodeButtonDES_clicked();

private:
    Ui::DESint *ui;
};

#endif // DESINT_H
