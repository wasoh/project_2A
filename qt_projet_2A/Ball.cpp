#include "Ball.h"


Ball::Ball()
{
}

Ball::Ball(String name){
	
	setType(name);
	if (name == "vert"){
		setHSVmin(Scalar(70, 24, 121));
		setHSVmax(Scalar(100, 126, 255));

		setColour(Scalar(0, 255, 0));
	}
	if (name == "rouge"){
        setHSVmin(Scalar(0, 30, 225));
        setHSVmax(Scalar(17, 80, 255));

		setColour(Scalar(0, 0, 255));
	}
	if (name == "blanc"){
        setHSVmin(Scalar(0, 0, 0));
        setHSVmax(Scalar(5, 5, 255));

		setColour(Scalar(255, 255, 255));
	}
}

Ball::~Ball()
{
}

int Ball::getXPos(){

	return Ball::xPos;
}

void Ball::setXPos(int x){

	Ball::xPos = x;
}
int Ball::getYPos(){

	return Ball::yPos;
}

void Ball::setYPos(int y){

	Ball::yPos = y;
}

Scalar Ball::getHSVmin(){

	return Ball::HSVmin;
}
Scalar Ball::getHSVmax(){

	return Ball::HSVmax;
}
void Ball::setHSVmin(Scalar min){

	Ball::HSVmin = min;
}
void Ball::setHSVmax(Scalar max){

	Ball::HSVmax = max;
}
