#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingballs.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    cam = new Camera();
    connexion_ssh = new Ssh(hostname,user,password,port);

    int fps = 1000/25;
    QTimer *qTimer = new QTimer(this);
    qTimer->setInterval(fps);
    connect(qTimer, SIGNAL(timeout()), this, SLOT(displayFrame()));
    qTimer->start();

    connect(ui->btnManuel, SIGNAL(clicked(bool)), this, SLOT(ModeManuel()));
    connect(ui->btnAssiste, SIGNAL(clicked(bool)), this, SLOT(OpenSetting()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayFrame() {
    //capture a frame from the webcam
    cv::Mat frame = cam->rechecherBalles();
    cv::cvtColor(frame, frame, CV_RGB2BGR);
    QImage image = QImage((uchar*) (frame.data), frame.cols, frame.rows, frame.step, QImage::Format_RGB888);

    //set the image of the label to be the captured frame and resize the label appropriately
    ui->label_cam->setPixmap(QPixmap::fromImage(image).scaled(ui->label_cam->width(), ui->label_cam->height(),Qt::KeepAspectRatio));

    //ui->label->resize(ui->label->pixmap()->size());
}

void MainWindow::OpenSetting(){
    SettingBalls *dialog = new SettingBalls(this,cam);
    dialog->exec();
}

void MainWindow::ModeManuel(){
    if(!modeManuel)
    {
        qDebug("Mode Manuel");
        try{
            connexion_ssh->Ssh_Connexion();
            connexion_ssh->Ssh_Identification();
            connexion_ssh->Ssh_Lancer("python /home/robot/CodePython/ps3.py");
            ui->btnManuel->setText("Manuel <On>");
        }
        catch(const std::bad_alloc &)
        {
            qDebug("Impossible de se connecter");
        }
    }
    else
    {
        connexion_ssh->Ssh_Terminer();
        ui->btnManuel->setText("Manuel <Off>");
    }
}
