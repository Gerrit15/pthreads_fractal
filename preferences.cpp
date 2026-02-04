#include "preferences.h"

void load_prefs(preferences &pref, int argc, char* argv[]) {
	pref.width = 30*64;
	pref.height = 23*64;
	pref.max_iteration = 1000;
	pref.max_threads = 5;
	pref.max_mod = 2;
	pref.outfile = "out.ppm";
}
