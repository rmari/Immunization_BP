#include <array>
#include "MP_algo.h"

void
MPalgo::iterate(){

	for(auto m = messages.begin(); m != messages.end(); m++){
		double new_val = MP_iteration(m);
	}
	
}
