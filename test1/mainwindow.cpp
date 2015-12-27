#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QLabel>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    cv::Mat test_image = cv::imread("lena.jpg");
    if(!test_image.data){
        QMessageBox msg;
        msg.setText("Could not load image");
        msg.exec();
    }
    QImage imgIn= QImage((uchar*) test_image.data, test_image.cols, test_image.rows, test_image.step, QImage::Format_RGB888);

    ui->label->setPixmap(QPixmap::fromImage(imgIn));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    cv::Mat test_image = cv::imread("lena.jpg");
    if(!test_image.data){
        QMessageBox msg;
        msg.setText("Could not load image");
        msg.exec();
    }

    QImage imgIn= QImage((uchar*) test_image.data, test_image.cols, test_image.rows, test_image.step, QImage::Format_RGB888);

    ui->label_2->setPixmap(QPixmap::fromImage(imgIn));

}

