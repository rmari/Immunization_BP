#include "MP_algo.h"

void
MPalgo::iterate(){

	for(vector<ScalarMessage>::iterator m = messages.begin(); m != messages.end(); m++){
		MP_iteration(m);
	}

	// parallel update: wait a full iteration for updating the message values 
	for(vector<ScalarMessage>::iterator m = messages.begin(); m != messages.end(); m++){
		(*m).setValue();
	}

}
