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
	SDL_Rect ding_rect;
	
	SDL_Rect ding_direction;
	
	int ding_colour;
	ding();
	ding(int a, int b, int c, int d, int e, int f);
	~ding();
	SDL_Rect mache_Posi();
	SDL_Rect check_edge(SDL_Rect ding_rect);
	SDL_Rect change_direction(SDL_Rect direction);
	SDL_Rect updateposition();
	
	
	

};

