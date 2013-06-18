#include <math.h>
#include "SIR_MP.h"

// The SIR Message Passing iteration. 
// This is a method to modify for each problem (immunization, spreading, etc)
double
SIR_MP::MP_iteration(vector<ScalarMessage>::iterator m){ 
	// Right now, this is written for the spreading problem, eq (21)-(9) in the notes

	int i = (*m).master_site->name;
	if ( gconf[i] ){
		(*m).new_value = 0;
		return 0;
	}
	else{
		double new_val=1;
		for(vector<ScalarMessage*>::iterator master = (*m).master_messages.begin(); master != (*m).master_messages.end(); master++){
			new_val *= (1-w*(1-(*master)->value));
		}
		(*m).new_value = new_val;
		return new_val;
	}
}

void
SIR_MP::exportFields(vector<double> *fields){
	// Right now, this is written for the spreading problem, eq (10) in the notes

	// determine who is spreader at the moment
	for(int i=0; i<g->siteNb(); i++){
		if ( gconf[i] )
			(*fields)[i] = 0;
		else
			(*fields)[i] = 1;
	}

	// compile messages
	for(vector<ScalarMessage>::iterator m = messages.begin(); m != messages.end(); m++){
		int j = (*m).slave_site->name;
		(*fields)[j] *= (1-w*(1-(*m).value));
	}

}

SIR_MP::SIR_MP(const Graph &gr) : MPalgo(gr) {
	gconf = new int [ g->siteNb() ];
	for(int i = 0; i < g->siteNb(); i++ )
		gconf[i] = 0;

	w = 0.1; // this hard-coding should disappear
	log_1mw = log(1-w);

}
SIR_MP::~SIR_MP(){
	delete [] gconf;
}
