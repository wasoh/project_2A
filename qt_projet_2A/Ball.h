#pragma once
#include <string>
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace std;
using namespace cv;



class Ball
{
public:
	Ball(void);
	~Ball(void);

	Ball(string name);

	int getXPos();
	void setXPos(int x);

	int getYPos();
	void setYPos(int y);

	Scalar getHSVmin();
	Scalar getHSVmax();

	void setHSVmin(Scalar min);
	void setHSVmax(Scalar max);

	String getType(){ return type; }
	void setType(String t){ type = t; }

	Scalar getColour(){
		return Colour;
	}
	void setColour(Scalar c){
		Colour = c;
	}

private:
	int xPos, yPos;
	string type;
	Scalar HSVmin, HSVmax;
	Scalar Colour;
};

