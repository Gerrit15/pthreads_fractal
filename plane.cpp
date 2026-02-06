#include "plane.h"

plane::plane(int argc, char* argv[]) {
	if(load_prefs(this->pref, argc, argv)) {exit(1);}
	//we generally make board way too big for the stack, so to the heap we go
	this->data = new int[this->pref.width*this->pref.height];
	this->count_lock = PTHREAD_MUTEX_INITIALIZER;
	this->count = 0;
}

plane::~plane() {
	delete[] data;
}

//runs the data on each item in our plane
void plane::simulate() {
	pthread_t threads[this->pref.max_threads]; //thread pool setup-- they'll grab jobs from the "queue" iteratively
	int thread_ret[this->pref.max_threads];
	for(int i = 0; i < this->pref.max_threads; ++i) {thread_ret[i] = pthread_create(threads+i, NULL, single_pixel, (void*) this);}
	//join the threads. Blocks a little weird, hypothetically, potentially, but 
	//doesn't really matter that much in the scope of things
	for(int i = 0; i < this->pref.max_threads; ++i) {
		pthread_join(threads[i], NULL);
		if(thread_ret[i] != 0) {std::cerr << "Thread " << i << " returned with status " << thread_ret[i] << std::endl;} //didn't really impl this but safe than sorry
	}
}

//generatic output to a file function.
void plane::output() {
	std::ofstream outfile(this->pref.outfile);
	if(!outfile.is_open()) {
		std::cerr << "Failed to open" << this->pref.outfile << std::endl;
		return;
	}

	//ppm file format is "P[1/2/3] \n [size x] [size y]\n [pixel data] [pixel data]..."
	outfile << "P3\n" << this->pref.width << " " << this->pref.height << "\n255" << "\n";
	for(int i = 0; i < this->pref.height; ++i) {
		for(int j = 0; j < this->pref.width; ++j) {
			outfile << "0 " << this->data[i*this->pref.width+j] << " 0" << std::endl;
		}
	}
	outfile.close();
}

void* single_pixel(void* complex_plane) {
	//yes I know it's a bad naming convention.
	plane* cplx_plane = (plane*)complex_plane;
	int index;
	int cap;
	int x, y, i;
	//cplx_num z, z0;
	double z[2], z0[2];
	while(1) {
		pthread_mutex_lock(&(cplx_plane->count_lock));
		index = cplx_plane->count;
		cplx_plane->count += cplx_plane->pref.width; //basically reserving the entire row for this thread. less mutex locks
		pthread_mutex_unlock(&(cplx_plane->count_lock));
		if(index >= cplx_plane->pref.width*cplx_plane->pref.height) {break;}
		cap = index+cplx_plane->pref.width;
		for(; index < cap; ++index) {
			x = index % (cplx_plane->pref.width); //index = y*WIDTH+x
			y = (index-x)/(cplx_plane->pref.width); //note: due to the way width and height are determined, the parenthesis are necessesary!!

			z[0] = 0;
			z[1] = 0;
			z0[0] = (3*x)/((float)cplx_plane->pref.width) - 2.5;
			z0[1] = (2.3*y)/((float)cplx_plane->pref.height) - 1.15;

			//instead of calling recursively, just set a max iteration depth
			//and make sure it doesn't leave the known bounds of the set
			for(i = 0; i < cplx_plane->pref.max_iteration && z[0]*z[0]+z[1]*z[1] < 4.0; ++i) {
				//(a+bi)(a+bi) = a^2-b^2+2abi ==> Re(z^2) = a^2-b^2, Im(z^2) = 2ab
				//(a+bi)(a+bi)+c+di = a^2-b^2+c+2abi+di ==> Re(z^2) = a^2-b^2+c, Im(z^2) = 2ab+d
				z[0] = z[0]*z[0]-z[1]*z[1]+z0[0];
				z[1] = 2*z[0]*z[1]+z0[1];
			}

			//good news! no possible race condition, index is unique to this thread
			;
			cplx_plane->data[index] = 172*(i/(float)cplx_plane->pref.max_iteration);
		}
	}
	return NULL; //don't really need it to return anything
}
