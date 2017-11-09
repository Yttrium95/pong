#include "ding.h"
#include <SDL.h>
#include <iostream>
#include <stdlib.h>
#include "vektor.h"
#include "ball.h"
#include <math.h>
#define HEIGHT 800
#define WIDTH  800
#define NULL 0





ding::ding()
{
	
	this->ding_rect.x = 0;
	this->ding_rect.y = 0;
	this->ding_rect.w = 0;
	this->ding_rect.h = 0;
	
	this->ding_direction.x = 1;
	this->ding_direction.y = 1;
	int ding_colour = 200;
		
}



ding::ding(int a, int b, int c, int d, int e, int f)
{
	this->ding_direction.x = a;
	this->ding_direction.y = b;
	this->ding_rect.x = c;
	this->ding_rect.y = d;
	this->ding_rect.h = e;
	this->ding_rect.w = f;
	
}

ding::~ding()
{
}

SDL_Rect ding::set_Posi()
{
	this->ding_rect.x = this->ding_direction.x+ this->ding_rect.x;
	this->ding_rect.y = this->ding_direction.y+ this->ding_rect.y;
	return ding_rect;
}

SDL_Rect ding::check_edge(SDL_Rect ding_rect)
{
	if (ding_rect.x+ding_rect.w >= WIDTH || (ding_rect.x <= NULL))
	{
		this->ding_direction.x = this->ding_direction.x*(-1);
	}


	if (ding_rect.y+ding_rect.h >= HEIGHT || ding_rect.y <= NULL)
	{
		this->ding_direction.y = this->ding_direction.y*(-1);
	}

	return this->ding_rect;
}

SDL_Rect ding::change_direction(SDL_Rect direction)
{
	direction.x = direction.x*(-1);
	direction.y = direction.y*(-1);
	return direction;
}

SDL_Rect ding::updateposition()
{
	this->ding_rect.y = ding_rect.y;
	this->ding_rect.x = ding_rect.x;
	return ding_rect;

}

