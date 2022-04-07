#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "gpio.h"


class QTimer;

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_startButton_clicked();

    void on_stopButton_clicked();

    void on_numberSlider(int value);

    void on_timeout();

    void restart();

private:
    int m_led_handle;
    QTimer* m_timer;
    Gpio* m_gpio; //example
    bool m_status=false;
};

#endif // MAINWINDOW_H
