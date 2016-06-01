#include "mainwindow.h"
#include "ui_mainwindow.h"
#define hostname "192.168.0.1"
#define port 22
#define user "robot"
#define password "maker"

Ssh connexion_ssh(hostname,user,password,port);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    webcam.open(0);
//    int fps = 1000/25;
//    QTimer *qTimer = new QTimer(this);
//    qTimer->setInterval(fps);
//    connect(qTimer, SIGNAL(timeout()), this, SLOT(displayFrame()));
//    qTimer->start();
    connect(ui->btnManuel, SIGNAL(clicked(bool)), this, SLOT(ModeManuel()));
    connect(ui->btnSoloMode, SIGNAL(clicked(bool)), this, SLOT(ModeSolo()));
    connect(ui->btnAssiste, SIGNAL(clicked(bool)),this, SLOT(ModeAssis()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayFrame() {
    //capture a frame from the webcam
    cv::Mat frame = captureFrame();
    QImage image = getQImageFromFrame(frame);
    QImage image2 = ProcessingFrame(frame);

    //set the image of the label to be the captured frame and resize the label appropriately
    ui->label_cam->setPixmap(QPixmap::fromImage(image).scaled(ui->label_cam->width(), ui->label_cam->height(),Qt::KeepAspectRatio));
    ui->label_camTraitement->setPixmap(QPixmap::fromImage(image2).scaled(ui->label_camTraitement->width(), ui->label_camTraitement->height(),Qt::KeepAspectRatio));

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

QImage MainWindow::ProcessingFrame(cv::Mat frame) {
    // Grayscale conversion (in-place operation)
    Mat src_gray;
    cv::cvtColor(frame, frame, CV_RGB2BGR);
    cv::cvtColor(frame, src_gray, CV_BGR2GRAY);
    GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );
    return QImage((uchar*) (frame.data), frame.cols, frame.rows, frame.step, QImage::Format_RGB888);
}

void MainWindow::ModeManuel(){
    qDebug("Mode Manuel");
    connect(ui->btnStop, SIGNAL(clicked(bool)), this, SLOT(Stop()));
    //connexion_ssh.Ssh_Connexion();
    //connexion_ssh.Ssh_Identification();
    //connexion_ssh.Ssh_Lancer("python /home/robot/CodePython/ps3.py");
}

void MainWindow::ModeSolo(){
    qDebug("Mode Solo");
    connect(ui->btnStop, SIGNAL(clicked(bool)), this, SLOT(Stop()));
    //connexion_ssh.Ssh_Connexion();
    //connexion_ssh.Ssh_Identification();
    //connexion_ssh.Ssh_Lancer("python /home/robot/CodePython/ftg");
}

void MainWindow::ModeAssis(){
    qDebug("Mode Assisté");
    connect(ui->btnStop, SIGNAL(clicked(bool)), this, SLOT(Stop()));
    connexion_ssh.Ssh_Connexion();
    connexion_ssh.Ssh_Identification();
    // Ajouter code du mode assisté
    connexion_ssh.Ssh_Lancer("python /home/robot/CodePython/assis");
}

void MainWindow::Stop(){
    qDebug("Stop");
    connexion_ssh.Ssh_Terminer();
}
