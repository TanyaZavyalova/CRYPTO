#ifndef VIGENER_H
#define VIGENER_H

#include <QMainWindow>

namespace Ui {
class vigener;
}

class vigener : public QMainWindow
{
    Q_OBJECT

public:
    explicit vigener(QWidget *parent = 0);
    ~vigener();

private slots:

    void on_encodeButton_clicked();

    void on_decodeButton_clicked();


    void on_openInput_clicked();

    void on_openOutput_clicked();

private:
    Ui::vigener *ui;
};

#endif // VIGENER_H
