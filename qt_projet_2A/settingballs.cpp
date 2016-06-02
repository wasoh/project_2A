#include "settingballs.h"
#include "ui_settingballs.h"
#include <QSlider>
#include <QDebug>

SettingBalls::SettingBalls(QWidget *parent, Camera *camera) :
    QDialog(parent),
    ui(new Ui::SettingBalls)
{
    ui->setupUi(this);
    this->cam = camera;
    this->ballCopie= cam->getBalls();

    listSlider.reserve(6);
    listSlider.push_back(ui->sliderhmin);
    listSlider.push_back(ui->slidersmin);
    listSlider.push_back(ui->slidervmin);
    listSlider.push_back(ui->sliderhmax);
    listSlider.push_back(ui->slidersmax);
    listSlider.push_back(ui->slidervmax);

    listLable.reserve(6);
    listLable.push_back(ui->labelhmin);
    listLable.push_back(ui->labelsmin);
    listLable.push_back(ui->labelvmin);
    listLable.push_back(ui->labelhmax);
    listLable.push_back(ui->labelsmax);
    listLable.push_back(ui->labelvmax);

    for(int i=0; i<6;i++)
    {
        connect(listSlider[i], SIGNAL(valueChanged(int)), listLable[i], SLOT(setNum(int)));
    }

    chargeSettingBall(0);
}

void SettingBalls::chargeSettingBall(int id)
{
    Ball b = ballCopie.operator [](id);

    ui->sliderhmin->setValue(b.getHSVmin()[0]);
    ui->slidersmin->setValue(b.getHSVmin()[1]);
    ui->slidervmin->setValue(b.getHSVmin()[2]);
    ui->sliderhmax->setValue(b.getHSVmax()[0]);
    ui->slidersmax->setValue(b.getHSVmax()[1]);
    ui->slidervmax->setValue(b.getHSVmax()[2]);

}

SettingBalls::~SettingBalls()
{
    delete ui;
}
