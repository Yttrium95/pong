#include <SDL.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "vektor.h"
#include "ball.h"
#include <math.h>
#include "ding.h"
#pragma once

bool collision_detection(ding ding1, ding ding2)
{
	if ((ding1.ding_rect.y >= ding2.ding_rect.y)&&(ding1.ding_rect.y <= ding2.ding_rect.y+ding2.ding_rect.h)&&(ding1.ding_rect.x >= ding2.ding_rect.x)&&(ding1.ding_rect.x <= ding2.ding_rect.x+ding2.ding_rect.w))
	{
		return true;
	}

	else if ((ding2.ding_rect.y >= ding1.ding_rect.y)&&(ding2.ding_rect.y <= ding1.ding_rect.y+ding1.ding_rect.h)&&(ding2.ding_rect.x >= ding1.ding_rect.x)&&(ding2.ding_rect.x <= ding1.ding_rect.x+ding1.ding_rect.w))
	{
		return true;
	}

	else
	{
		return false;
	}
}

	

