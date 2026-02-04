#include "plane.h"

int main(int argc, char* argv[]) {
	std::string outpath = "out.ppm";
	plane complex_grid(argc, argv);
	complex_grid.simulate();
	complex_grid.output();
}
