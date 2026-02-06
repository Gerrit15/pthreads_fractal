#include "plane.h"
//#include <ctime>

int main(int argc, char* argv[]) {
	std::string outpath = "out.ppm";
	//std::clock_t times[3];
	//times[0] = clock();
	plane complex_grid(argc, argv);
	complex_grid.simulate();
	//times[1] = clock();
	complex_grid.output();
	//times[2] = clock();
	//std::cout << "Time to simulate: " << times[1] - times[0] << ", time to output: " << times[2] - times[1] << std::endl;
}
