#include "plane.h"

plane::plane() {
	this->data = new int[WIDTH*HEIGHT];
	for(int i = WIDTH*HEIGHT - 1; i >= 0; --i) {data[i] = 0;}
}

plane::~plane() {
	delete[] data;
}

void plane::output(std::string& outpath) {
	std::ofstream outfile(outpath);
	if(!outfile.is_open()) {
		std::cerr << "Failed to open" << outpath << std::endl;
		return;
	}
	outfile << "P1\n" << WIDTH << " " << HEIGHT << "\n";
	for(int i = 0; i < HEIGHT; ++i) {
		for(int j = 0; j < WIDTH; ++j) {
			outfile << this->data[i*WIDTH + j] << " ";
		}
		outfile << "\n";
	}
	outfile.close();
}

void plane::simulate() {
	for(int i = 0; i < HEIGHT; ++i) {
		for(int j = 0; j < WIDTH; ++j) {
				this->data[i*WIDTH + j] = this->single_tile(j, i); //j is real, i is complex
			}
		}
}

bool plane::single_tile(int i, int j) {
	cplx_num z = {(4*i)/((float)WIDTH) - 2, (4*j)/((float)HEIGHT) - 2};
	//std::cout << "Got base z: " << z << std::endl;
	for(int i = 0; i < ITR_MAX && std::abs(z) < MAX_MOD; ++i) {
		z = z*z;// + (floatc)2*complex_one;
		//std::cout << "\tnew z: " << z << ", |z|: " << abs(z) << std::endl;
	}
	if(std::abs(z) >= MAX_MOD) {return false;}
	return true;
}
