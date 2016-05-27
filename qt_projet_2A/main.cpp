#include "mainwindow.h"
#include <QApplication>
#include "camera.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    Camera* cam = new Camera();
    while(1)
    {
        Mat img = cam->rechecherBalles();
        cv::imshow("Cam",img);
        cv::waitKey(30);
    }
    return a.exec();
}
