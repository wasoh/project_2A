#ifndef SETTINGBALLS_H
#define SETTINGBALLS_H

#include <QDialog>
#include <vector>
#include <QLabel>
#include <QSlider>

#include "Ball.h"
#include "camera.h"

namespace Ui {
class SettingBalls;
}

class SettingBalls : public QDialog
{
    Q_OBJECT

public:
    explicit SettingBalls(QWidget *parent=0, Camera *camera=NULL);
    ~SettingBalls();

private:
    Ui::SettingBalls *ui;
    Vector<Ball> ballCopie;
    Camera *cam;
    Vector<QLabel*> listLable;
    Vector<QSlider*> listSlider;
    void chargeSettingBall(int id);

signals:

public slots:

};

#endif // SETTINGBALLS_H
