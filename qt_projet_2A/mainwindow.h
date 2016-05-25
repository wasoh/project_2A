#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <opencv2/highgui/highgui.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    cv::VideoCapture webcam;
    QImage getQImageFromFrame(cv::Mat frame);
    cv::Mat captureFrame();

private:
    Ui::MainWindow *ui;

public slots:
    void displayFrame();

};

#endif // MAINWINDOW_H
