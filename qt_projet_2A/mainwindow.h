#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

// Ssh
#include <libssh/libssh.h>
#include "ssh.h"

// OpenCV
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    VideoCapture webcam;
    QImage getQImageFromFrame(cv::Mat frame);
    QImage ProcessingFrame(cv::Mat frame);
    Mat captureFrame();

private:
    Ui::MainWindow *ui;

public slots:
    void displayFrame();

private slots:
    void ModeManuel();
    void ModeSolo();
    void ModeAssis();
    void Stop();
};

#endif // MAINWINDOW_H
