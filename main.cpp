#include "plane.h"

int main() {
	std::string outpath = "out.ppm";
	plane complex_grid{};
	complex_grid.simulate();
	complex_grid.output(outpath);
}
