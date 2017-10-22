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
	this->ding_rect.w = 100;
	this->ding_rect.h = 100;
	
	this->ding_direction.x = 1;
	this->ding_direction.y = 1;
		
}

SDL_Surface ding::GetImage()
{
	SDL_Surface *image = SDL_LoadBMP("ball.bmp");
	return *image;
}


ding::ding(int a, int b)
{
	this->ding_direction.x = a;
	this->ding_direction.y = b;
}

ding::~ding()
{
}

SDL_Rect ding::mache_Posi()
{
	this->ding_rect.x = this->ding_direction.x+ this->ding_rect.x;
	this->ding_rect.y = this->ding_direction.y+ this->ding_rect.y;
	return ding_rect;
}

SDL_Rect ding::check_edge(SDL_Rect ding_rect)
{
	if (ding_rect.x >= WIDTH || (ding_rect.x <= NULL))
	{
		this->ding_direction.x = this->ding_direction.x*(-1);
	}


	if (ding_rect.y >= HEIGHT || ding_rect.y <= NULL)
	{
		this->ding_direction.y = this->ding_direction.y*(-1);
	}

	return this->ding_rect;
}


