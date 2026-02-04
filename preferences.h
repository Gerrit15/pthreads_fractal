#ifndef PREF_HEADER
#define PREF_HEADER
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

/*
* =======Options=======
* -s	the scale.
* -t	how many threads
* -o	outfile path
* -i	maximum iteration
* -h	displays help
* =====================
*/

typedef struct {
	int width;
	int height;
	int max_iteration;
	int max_threads;
	int max_mod;
	std::string outfile;
} preferences;

int load_prefs(preferences& pref, int argc, char* argv[]);
#endif
