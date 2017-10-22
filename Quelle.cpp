
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
    
	ding ding1(7,3);
	ding ding2(4, 8);

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
		collision_detection(ding1, ding2);

		SDL_BlitSurface(&(ding1.GetImage()), 0, screen, &ding1.ding_rect);
		SDL_BlitSurface(&(ding2.GetImage()), 0, screen, &ding2.ding_rect);
		SDL_Flip(screen);
		Sleep(10);
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		
	}

	return 0;
	

}