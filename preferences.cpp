#include "preferences.h"
/*
* =======Options=======
* -s	the scale.
* -t	how many threads
* -o	outfile path
* -i	maximum iteration
* -h	displays help
* =====================
*/
int load_prefs(preferences &pref, int argc, char* argv[]) {
	//setting defaults
	pref.width = 30*32;
	pref.height = 23*32;
	pref.max_iteration = 100;
	pref.max_threads = 5;
	pref.outfile = "out.ppm";

	//read cmd line
	for(int i = argc - 1; i >= 0; --i) {
		if(strcmp(argv[i], "-h") == 0) {
			std::cout << "=======Options=======" << std::endl
								<< "-s\tthe scale. Default: 32" << std::endl
								<< "-t\thow many threads. Default: 5" << std::endl
								<< "-o\toutfile path. Default: out.ppm" << std::endl
								<< "-i\tmaximum iteration. Default: 100" << std::endl
								<< "-h\tdisplays help" << std::endl
								<< "=====================" << std::endl;
			return 1;
		}
		if(strcmp(argv[i], "-s") == 0) {
			if(i+1 < argc) {
				int scale = atoi(argv[i+1]);
				if(scale == 0) {std::cout << "Please provide a valid scale" << std::endl; return 1;}
				pref.width = 30*scale;
				pref.height = 23*scale;
			}
		}
		if(strcmp(argv[i], "-t") == 0) {
			if(i+1 < argc) {
				int threads = atoi(argv[i+1]);
				if(threads == 0) {std::cout << "Please provide a valid number of threads" << std::endl; return 1;}
				pref.max_threads = threads;
			}
		}
		if(strcmp(argv[i], "-o") == 0) {
			if(i+1 < argc) {pref.outfile = argv[i+1];}
		}
		if(strcmp(argv[i], "-i") == 0) {
			if(i+1 < argc) {
				int iterations = atoi(argv[i+1]);
				if(iterations == 0) {std::cout << "Please provide a valid iteration max" << std::endl; return 1;}
				pref.max_iteration = iterations;
			}
		}
	}
	return 0;
}
