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

bool collision_detection(ding ding1, ding ding2, ding ding3)
{
	if ((ding1.ding_rect.y >= ding2.ding_rect.y)&&(ding1.ding_rect.y <= ding2.ding_rect.y+ding2.ding_rect.h)&&(ding1.ding_rect.x >= ding2.ding_rect.x+47)&&(ding1.ding_rect.x <= ding2.ding_rect.x+50))
	{
		return true;
	}

	else if ((ding2.ding_rect.y >= ding1.ding_rect.y)&&(ding2.ding_rect.y <= ding1.ding_rect.y+ding1.ding_rect.h)&&(ding2.ding_rect.x+47 <= ding1.ding_rect.x)&&(ding2.ding_rect.x+50 >= ding1.ding_rect.x))
	{
		return true;
	}

	else if ((ding1.ding_rect.y >= ding3.ding_rect.y) && (ding1.ding_rect.y <= ding3.ding_rect.y+ding3.ding_rect.h) && (ding1.ding_rect.x+50 >= ding3.ding_rect.x) && (ding1.ding_rect.x+50 <= ding3.ding_rect.x+3))
	{
		return true;
	}
	else if ((ding3.ding_rect.y >= ding1.ding_rect.y) && (ding3.ding_rect.y <= ding1.ding_rect.y + ding1.ding_rect.h) && (ding3.ding_rect.x+3 >= ding1.ding_rect.x+50) && (ding3.ding_rect.x <= ding1.ding_rect.x+50))
	{
		return true;
	}

	else
	{
		return false;
	}
}

	

