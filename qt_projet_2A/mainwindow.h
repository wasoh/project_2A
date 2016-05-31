#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>

// OpenCV
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>

#include "camera.h"

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

private:
    Ui::MainWindow *ui;
    Camera* cam;

public slots:
    void displayFrame();

};

#endif // MAINWINDOW_H
