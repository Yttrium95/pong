
#include <SDL.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "vektor.h"
#include "ball.h"
#include <math.h>
#include "ding.h"
#include "collision_detection.h"

#define HEIGHT 800
#define WIDTH  800
#define NULL 0


int wmain(int argc, char **argv[])

{

	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cerr << "Konnte SDL nicht initialisieren: " << SDL_GetError() << std::endl;
		return 1;
	}

	atexit(&SDL_Quit);


	SDL_Surface *screen = SDL_SetVideoMode(HEIGHT, WIDTH, 32, SDL_DOUBLEBUF);

	if (!screen)
	{

		std::cout << "Fehler" << SDL_GetError() << std::endl;
		return 1;

	}
    
	ding ding1(5,-2, 100, 400, 50, 50);
	ding ding2(0,-3, 50, 300, 200, 50);
	ding ding3(0, 3, 700, 300, 200, 50);
	

	bool running = true;
	
	while (running)
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
					case SDL_QUIT:
					running = false;
					return 0;
			}
		}
		
		ding1.mache_Posi();
		ding1.check_edge(ding1.ding_rect);
		
		ding2.mache_Posi();
		ding2.check_edge(ding2.ding_rect);
		
		ding3.mache_Posi();
		ding3.check_edge(ding2.ding_rect);
		
		SDL_FillRect(screen, &(ding1.ding_rect), 250);
		SDL_FillRect(screen, &(ding2.ding_rect), 200);
		SDL_FillRect(screen, &(ding3.ding_rect), 200);

		SDL_Flip(screen);
		Sleep(10);
		
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		
		SDL_FreeSurface(screen);

		if (collision_detection(ding1, ding2, ding3))
		{
			std::cout << "hi" << std::endl;
			ding1.ding_direction.x=(-1)*ding1.ding_direction.x;
			ding2.ding_direction.x = (-1)*ding2.ding_direction.x;
			ding3.ding_direction.x = (-1)*ding3.ding_direction.x;
		}
		
	}

	return 0;
	

}