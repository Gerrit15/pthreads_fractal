#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>
#include <string>

//width and height are just the dimensions of the output iamge
//30:23 is the ratio x:y
#define SCALE 8
#define WIDTH 30*SCALE
#define HEIGHT 23*SCALE
//mod as in modulo, magnitude of a complex numeber
#define MAX_MOD 2
//how many iterations can you try before saying "good enough"
#define ITR_MAX 1000


typedef std::complex<double> cplx_num;
static const cplx_num complex_const = 1; //complex constant for z = z^2+c

class plane {
public:
	plane();
	~plane();
	void simulate();
	void output(std::string& outpath);
private:
	int *data;
	bool single_tile(int i, int j);
};
