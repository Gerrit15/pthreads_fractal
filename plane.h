#include <cmath>
#include <complex>
#include <fstream>
#include <iostream>
#include <string>

#define WIDTH 256*4
#define HEIGHT 256*4
#define MAX_MOD 2.5
#define ITR_MAX 10


typedef std::complex<double> cplx_num;
static const cplx_num complex_one = 1;

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
