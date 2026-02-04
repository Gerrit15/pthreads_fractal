#ifndef PLANE_HEADER
#define PLANE_HEADER
#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>
#include <string>
#include <pthread.h>

#include "preferences.h"

typedef std::complex<double> cplx_num;

class plane {
public:
	plane(int argc, char* argv[]);
	~plane();
	void simulate();
	void output();
	//count is the current lead 'index' of the threads-- when a thread finishes 
	//it'll go here (thu the mutex, in a sense) and see that "count" is at x, so it'll start
	//operations again at plane->data[x], up to plane->data[x+WIDTH-1] (inclusive)
	pthread_mutex_t count_lock;
	int count; 
	int *data;
	preferences pref;
};

void* single_pixel(void* compex_plane);
#endif
