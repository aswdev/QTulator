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

private:
    Ui::MainWindow *ui;

private slots:
    void digit_pressed();
    void on_pushButton_przecinek_released();
    void zmiana_znaku();

    void on_pushButton_czysc_released();
    void on_pushButton_rownosc_released();
    void dzialania();
};

#endif // MAINWINDOW_H
