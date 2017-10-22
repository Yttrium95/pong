#include <SDL.h>
#include <iostream>
#include <stdlib.h>
#include "vektor.h"
#include "ball.h"
#include <math.h>
#pragma once
#define HEIGHT 800
#define WIDTH  800
#define NULL 0

class ding
{
public:
	SDL_Surface GetImage();
	SDL_Rect ding_rect;
	
	SDL_Rect ding_direction;
	
	ding();
	ding(int a, int b);
	~ding();
	SDL_Rect mache_Posi();
	SDL_Rect check_edge(SDL_Rect ding_rect);
	
	
	

};

