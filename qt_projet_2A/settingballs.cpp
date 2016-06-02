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
    this->ballCopie= cam->getBalls().clone();

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

    chargeSettingBall(0);
    for(int i=0; i<6;i++)
    {
        connect(listSlider[i], SIGNAL(valueChanged(int)), listLable[i], SLOT(setNum(int)));
    }

    for(int i=0; i<ballCopie.size();i++)
    {
        ui->comboBox->addItem(QString::fromStdString(ballCopie[i].getType()));
    }
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(chargeSettingBall(int)));

    connect(ui->buttonBox, SIGNAL(accepted()),this,SLOT(validation()));
    connect(ui->buttonBox, SIGNAL(rejected()),this, SLOT(close()));
}

void SettingBalls::chargeSettingBall(int id)
{
    if(!init)
    {
        ballCopie[idBall].setHSVmax(Scalar(ui->sliderhmax->value(),ui->slidersmax->value(),ui->slidervmax->value()));
        ballCopie[idBall].setHSVmin(Scalar(ui->sliderhmin->value(),ui->slidersmin->value(),ui->slidervmin->value()));
        init = false;
    }
    idBall = id;
    Ball b = ballCopie.operator [](id);

    ui->sliderhmin->setValue(b.getHSVmin()[0]);
    ui->slidersmin->setValue(b.getHSVmin()[1]);
    ui->slidervmin->setValue(b.getHSVmin()[2]);
    ui->sliderhmax->setValue(b.getHSVmax()[0]);
    ui->slidersmax->setValue(b.getHSVmax()[1]);
    ui->slidervmax->setValue(b.getHSVmax()[2]);
}

void SettingBalls::validation()
{
    ballCopie[idBall].setHSVmax(Scalar(ui->sliderhmax->value(),ui->slidersmax->value(),ui->slidervmax->value()));
    ballCopie[idBall].setHSVmin(Scalar(ui->sliderhmin->value(),ui->slidersmin->value(),ui->slidervmin->value()));
    cam->setBalls(ballCopie);
    this->close();
}

SettingBalls::~SettingBalls()
{
    delete ui;
}

