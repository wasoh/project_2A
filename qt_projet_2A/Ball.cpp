#include "Ball.h"


Ball::Ball()
{
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