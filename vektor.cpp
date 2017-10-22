#include "vektor.h"
#include <stdlib.h>
#include <iostream>
#include <math.h>


vektor::vektor() {

	this->x = 1;
	this->y = 1;
}

vektor::vektor(int x, int y)
{
	this->x = x;
	this->y = y;
}

vektor vektor::operator=(vektor param)
{
	vektor temp;

	this->x = param.x;
	this->y = param.y;
	return (temp);

}

vektor vektor::operator+(vektor param)
{
	vektor temp;

	temp.x = this->x + param.x;
	temp.y = this->y + param.y;
	return (temp);
}

vektor vektor::operator*(vektor param)
{
	vektor temp;
	temp.x = this->x * param.x;
	temp.y = this->y * param.y;
	return (temp);
}




