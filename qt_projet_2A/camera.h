#ifndef CAMERA_H
#define CAMERA_H


#include <sstream>
#include <string>
#include <iostream>
#include <vector>

//local
#include "Ball.h"

#define ID_DEVICE       0
class Camera
{
public:
    Camera();
};

void on_trackbar(int, void*);
string intToString(int number);
void createTrackbars();
void drawObject(vector<Ball> theBalls, Mat &frame);
void morphOps(Mat &thresh);
void trackFilteredObject(Mat threshold, Mat HSV, Mat &cameraFeed);
void trackFilteredObject(Ball theBall, Mat threshold, Mat HSV, Mat &cameraFeed);
int test();

#endif // CAMERA_H
