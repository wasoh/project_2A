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
#include "camera.h"


#define hostname "192.168.62.103"
#define port 22
#define user "robot"
#define password "maker"
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
    Ssh* connexion_ssh;
    bool modeManuel = false;

private slots:
    void displayFrame();
    void ModeManuel();
};

#endif // MAINWINDOW_H
