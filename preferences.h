#include <string>
typedef struct {
	int width;
	int height;
	int max_iteration;
	int max_threads;
	std::string outfile;
} preferences;

void load_prefs(preferences& pref, int argc, char* argv[]);
