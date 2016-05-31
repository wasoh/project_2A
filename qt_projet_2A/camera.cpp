#include "camera.h"

Camera::Camera()
{
    //init
    calibrationMode = false;

    //open capture object at location zero (default location for webcam)
    capture.open(ID_DEVICE);
    capture.set(CV_CAP_PROP_FRAME_WIDTH, FRAME_WIDTH);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, FRAME_HEIGHT);

    balles.reserve(3);
    Ball vert("vert"), rouge("rouge"), blanc("blanc");
    balles.push_back(vert);
    balles.push_back(rouge);
    balles.push_back(blanc);

}

void on_trackbar(int, void*)
{//This function gets called whenever a
    // trackbar position is changed

}

void drawObject(vector<Ball> theBalls, Mat &frame){

    for (int i = 0; i < theBalls.size(); i++){

        cv::circle(frame, cv::Point(theBalls.at(i).getXPos(), theBalls.at(i).getYPos()), 10, cv::Scalar(0, 0, 255));
        cv::putText(frame, theBalls.at(i).getXPos() + " , " + theBalls.at(i).getYPos(), cv::Point(theBalls.at(i).getXPos(), theBalls.at(i).getYPos() + 20), 1, 1, Scalar(0, 255, 0));
        cv::putText(frame, theBalls.at(i).getType(), cv::Point(theBalls.at(i).getXPos(), theBalls.at(i).getYPos() - 30), 1, 2, theBalls.at(i).getColour());

    }
}

void morphOps(Mat &thresh){

    //create structuring element that will be used to "dilate" and "erode" image.
    //the element chosen here is a 3px by 3px rectangle

    Mat erodeElement = getStructuringElement(MORPH_RECT, Size(3, 3));
    //dilate with larger element so make sure object is nicely visible
    Mat dilateElement = getStructuringElement(MORPH_RECT, Size(8, 8));

    erode(thresh, thresh, erodeElement);
    erode(thresh, thresh, erodeElement);

    dilate(thresh, thresh, dilateElement);
    dilate(thresh, thresh, dilateElement);


}

void trackFilteredObject(Ball typeBall, Mat threshold, Mat &cameraFeed){

    vector<Ball> verts;

    Mat temp;
    threshold.copyTo(temp);
    //these two vectors needed for output of findContours
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    //find contours of filtered image using openCV findContours function
    findContours(temp, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
    //use moments method to find our filtered object

    bool objectFound = true;
    if (hierarchy.size() > 0) {
        int numObjects = hierarchy.size();
        //if number of objects greater than MAX_NUM_OBJECTS we have a noisy filter
        if (numObjects<MAX_NUM_OBJECTS){
            for (int index = 0; index >= 0; index = hierarchy[index][0]) {

                Moments moment = moments((cv::Mat)contours[index]);
                double area = moment.m00;

                //if the area is less than 20 px by 20px then it is probably just noise
                //if the area is the same as the 3/2 of the image size, probably just a bad filter
                //we only want the object with the largest area so we safe a reference area each
                //iteration and compare it to the area in the next iteration.
                if (area>MIN_OBJECT_AREA){

                    Ball vert;
                    vert.setXPos(moment.m10 / area);
                    vert.setYPos(moment.m01 / area);
                    vert.setType(typeBall.getType());
                    vert.setColour(typeBall.getColour());

                    verts.push_back(vert);

                    objectFound = true;

                }
                else objectFound = false;


            }
            //let user know you found an object
            if (objectFound == true){
                //draw object location on screen
                drawObject(verts, cameraFeed);
            }

        }
        else putText(cameraFeed, "TOO MUCH NOISE! ADJUST FILTER", Point(0, 50), 1, 2, Scalar(0, 0, 255), 2);
    }
}

Mat Camera::rechecherBalles()
{
    //Matrix to store each frame of the webcam feed
    Mat cameraFeed;
    Mat threshold;
    Mat HSV;

    //store image to matrix
    capture.read(cameraFeed);
    //convert frame from BGR to HSV colorspace
    cvtColor(cameraFeed, HSV, COLOR_BGR2HSV);

    for(int i=0; i < balles.size();i++){
        inRange(HSV, balles[i].getHSVmin(), balles[i].getHSVmax(), threshold);
        morphOps(threshold);
        trackFilteredObject(balles[i],threshold, cameraFeed);
    }


    return cameraFeed;
}
