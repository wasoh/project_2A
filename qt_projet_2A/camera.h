#ifndef CAMERA_H
#define CAMERA_H


#include <sstream>
#include <string>
#include <iostream>
#include <vector>

//local
#include "Ball.h"

#define ID_DEVICE       0
#define CALIBRATION_MODE       false

//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 480;

//max number of objects to be detected in frame
const int MAX_NUM_OBJECTS = 50;

//minimum and maximum object area
const int MIN_OBJECT_AREA = 20 * 20;
const int MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH / 1.5;

class Camera
{
public:
    Camera();
    Mat rechecherBalles();
    Vector<Ball> getBalls();
    void setBalls(Vector<Ball> ball);


private :
    VideoCapture capture;
    bool calibrationMode;
    Vector<Ball> balles;

};

void drawObject(vector<Ball> theBalls, Mat &frame);
void morphOps(Mat &thresh);
void trackFilteredObject(Ball theBall, Mat threshold, Mat &cameraFeed);

#endif // CAMERA_H
