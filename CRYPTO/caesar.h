#ifndef CAESAR_H
#define CAESAR_H

#include <QMainWindow>

namespace Ui {
class caesar;
}

class caesar : public QMainWindow
{
    Q_OBJECT

public:
    explicit caesar(QWidget *parent = 0);
    ~caesar();

private slots:
    void on_encodeButton_clicked();

    void on_decodeButton_clicked();

    void on_openInput_clicked();

    void on_openOutput_clicked();

private:
    Ui::caesar *ui;
};

#endif // CAESAR_H
