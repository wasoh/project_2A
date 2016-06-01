#include "settingballs.h"
#include "ui_settingballs.h"
#include <QSlider>

SettingBalls::SettingBalls(QWidget *parent, Vector<Ball> *balls, Camera *cam) :
    QWidget(parent),
    ui(new Ui::SettingBalls)
{
    ui->setupUi(this);
    this->cam = cam;
    this->ballCopie= &balls->clone();

    Vector<QSlider> listSlider;
    listSlider.resize(6);
    listSlider.push_back(new QSlider(ui->sliderhmin));
    listSlider.push_back(new QSlider(ui->slidersmin));
    listSlider.push_back(new QSlider(ui->slidervmin));
    listSlider.push_back(new QSlider(ui->sliderhmax));
    listSlider.push_back(new QSlider(ui->slidersmax));
    listSlider.push_back(new QSlider(ui->slidervmax));

    Vector<

    connect(horizontalSliders, SIGNAL(valueChanged(int)),
                verticalSliders, SLOT(setValue(int)));

}

SettingBalls::chargeSettingBall(int id)
{
    Ball b = ballCopie[id];

    ui->sliderhmin->setValue(b.getHSVmin()[0]);
    ui->slidersmin->setValue(b.getHSVmin()[1]);
    ui->slidervmin->setValue(b.getHSVmin()[2]);
    ui->sliderhmax->setValue(b.getHSVmin()[0]);
    ui->slidersmax->setValue(b.getHSVmin()[1]);
    ui->slidervmax->setValue(b.getHSVmin()[2]);

}

SettingBalls::~SettingBalls()
{
    delete ui;
}
