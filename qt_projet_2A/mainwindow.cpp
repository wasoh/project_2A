#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webcam.open(0);
    int fps = 1000/25;
    QTimer *qTimer = new QTimer(this);
    qTimer->setInterval(fps);
    connect(qTimer, SIGNAL(timeout()), this, SLOT(displayFrame()));
    qTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayFrame() {
    //capture a frame from the webcam
    cv::Mat frame = captureFrame();
    QImage image = getQImageFromFrame(frame);

    //set the image of the label to be the captured frame and resize the label appropriately
    ui->label->setPixmap(QPixmap::fromImage(image).scaled(ui->label->width(), ui->label->height(),Qt::KeepAspectRatio));

    //ui->label->resize(ui->label->pixmap()->size());
}

cv::Mat MainWindow::captureFrame()
{
    cv::Mat frame;
    //determine whether or not the webcam video stream was successfully initialized
    if(!webcam.isOpened())
    {
        qDebug() << "Camera initialization failed.";
    }

    //attempts to grab a frame from the webcam
    if (!webcam.grab()) {
        qDebug() << "Failed to capture frame.";
    }

    //attempts to read the grabbed frame and stores it in frame
    if (!webcam.read(frame)) {
        qDebug() << "Failed to read data from captured frame.";
    }

    return frame;
}

QImage MainWindow::getQImageFromFrame(cv::Mat frame) {
    //converts the color model of the image from RGB to BGR because OpenCV uses BGR
    cv::cvtColor(frame, frame, CV_RGB2BGR);
    return QImage((uchar*) (frame.data), frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
}
