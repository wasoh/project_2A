#pragma once
#include <string>
using namespace std;

class Ball
{
public:
	Ball();
	~Ball();

	int getXPos();
	void setXPos(int x);

	int getYPos();
	void setYPos(int y);

private:
	int xPos, yPos;
	string type;

};

