#ifndef SETTINGBALLS_H
#define SETTINGBALLS_H

#include <QWidget>
#include <QDialog>
#include <vector>

#include "Ball.h"
#include "camera.h"

namespace Ui {
class SettingBalls;
}

class SettingBalls : public QWidget
{
    Q_OBJECT
public:
    explicit SettingBalls(QWidget *parent, Vector<Ball> *balls, Camera *cam);
    ~SettingBalls();

private:
    Ui::SettingBalls *ui;
    Vector<Ball> *ballCopie;
    Camera *cam;

signals:

public slots:

};

#endif // SETTINGBALLS_H
