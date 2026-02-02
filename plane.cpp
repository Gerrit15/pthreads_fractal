#include "plane.h"

plane::plane() {
	//we generally make board way too big for the stack, so to the heap we go
	this->data = new int[WIDTH*HEIGHT];
}

plane::~plane() {
	delete[] data;
}

//runs the data on each item in our plane
void plane::simulate() {
	for(int i = 0; i < HEIGHT; ++i) {
		for(int j = 0; j < WIDTH; ++j) {
				//for each pixel in the grid, go and see what happens when called recursively
				this->data[i*WIDTH + j] = this->single_tile(j, i); //j is real, i is complex
			}
		}
}

//simulates the recursion on each pixel
bool plane::single_tile(int i, int j) {
	cplx_num z = 0;
	//scaling the pixel into [-2.5, 0.5] x [-1.15, 1.15] because it's a
	//good ratio to display the set, and the set is inside those bounds
	cplx_num z0 = {(3*i)/((float)WIDTH) - 2.5, (2.3*j)/((float)HEIGHT) - 1.15};

	//instead of calling recursively, just set a max iteration depth
	//and make sure it doesn't leave the known bounds of the set
	for(int i = 0; i < ITR_MAX && std::abs(z) < MAX_MOD; ++i) {z = z*z+z0;}
	if(std::abs(z) >= MAX_MOD) {return false;}
	return true;
}

//generatic output to a file function.
void plane::output(std::string& outpath) {
	std::ofstream outfile(outpath);
	if(!outfile.is_open()) {
		std::cerr << "Failed to open" << outpath << std::endl;
		return;
	}

	//ppm file format is "P[1/2/3] \n [size x] [size y]\n [pixel data] [pixel data]..."
	outfile << "P1\n" << WIDTH << " " << HEIGHT << "\n";
	for(int i = 0; i < HEIGHT; ++i) {
		for(int j = 0; j < WIDTH; ++j) {
			outfile << this->data[i*WIDTH + j] << " ";
		}
		outfile << "\n"; //ppm doesn't care if it's newline or space to deliminate pixel data
	}
	outfile.close();
}
