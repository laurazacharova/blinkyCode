#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gpio.h"
#include "gpioconfig.h"
#include <lgpio.h>
#include <QTimer>

int TSLEEP = 500 ;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
   ,m_timer(new QTimer(this))
{
    setupUi(this);

    m_gpio= new Gpio(this);

    connect(m_timer, &QTimer::timeout, this, &MainWindow::on_timeout);
    numberLabel->setNum(numberSlider->value());

}

MainWindow::~MainWindow()
{
    delete m_timer;
}

void MainWindow::on_startButton_clicked()
{

    m_timer->start(TSLEEP);
}

void MainWindow::on_stopButton_clicked()
{
    m_timer->stop();
}

void MainWindow::on_numberSlider(int value)
{
    TSLEEP = 1000/value;
    MainWindow::restart();

}

void MainWindow::restart()
{
    MainWindow::on_stopButton_clicked();
    MainWindow::on_startButton_clicked();
}
void MainWindow::on_timeout()
{
    m_gpio->set(LEDS[0], m_status);
    m_status = !m_status;
    led->toggle();
}
