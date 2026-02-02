#include "plane.h"

plane::plane() {
	//we generally make board way too big for the stack, so to the heap we go
	this->data = new int[WIDTH*HEIGHT];
	//calloc it
	for(int i = WIDTH*HEIGHT - 1; i >= 0; --i) {data[i] = 0;}
}

plane::~plane() {
	delete[] data;
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
	//interpolate the (x, y) from the [0, WIDTH] space to [-2, 2], because the
	//mandelbrot should keep inside that space, so no reason to simulate outside
	cplx_num z = {(4*i)/((float)WIDTH) - 2, (4*j)/((float)HEIGHT) - 2};

	//instead of calling recursively, just set a max iteration depth and make sure it doesn't leav
	//the known bounds of the set
	std::cout << "Starting z: " << z << ", |z|: " << abs(z) << std::endl;
	for(int i = 0; i < ITR_MAX && std::abs(z) < MAX_MOD; ++i) {
		z = z*z;// + complex_const;
		std::cout << "\tnew z: " << z << ", |z|: " << abs(z) << std::endl;
	}
	if(std::abs(z) >= MAX_MOD) {return false;}
	return true;
}
