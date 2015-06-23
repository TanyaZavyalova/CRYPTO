#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
    }

class MainWindow : public QMainWindow
{
        Q_OBJECT
    
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
    
    private slots:
        void on_caesar_triggered();
    
        void on_vigener_triggered();
    
        void on_steganography_triggered();
    
        void on_DES_triggered();
    
    private:
        Ui::MainWindow *ui;
    };

#endif // MAINWINDOW_H
