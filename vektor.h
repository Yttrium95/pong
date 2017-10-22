#include <iostream>
#include <stdlib.h>
#include <math.h>
#pragma once


class vektor

{
	public:
		int x;
		int y;

	
		vektor();
		vektor(int x, int y);

		vektor operator= (vektor param);
		vektor operator+ (vektor param);
		vektor operator* (vektor param);
};
