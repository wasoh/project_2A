#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    Mat captureFrame();

private:
    Ui::MainWindow *ui;

public slots:
    void displayFrame();

};

#endif // MAINWINDOW_H
