#include "SIR_MP.h"

// The SIR Message Passing iteration. 
// This is the method to modify for each problem (immunization, spreading, etc)
double
SIR_MP::MP_iteration(vector<ScalarMessage>::iterator m){

	double new_val=1;
	double w;
	for(vector<ScalarMessage*>::iterator master = (*m).master_messages.begin(); master != (*m).master_messages.begin(); master++){
		new_val *= (1-w*(1-(*master)->value));
	}
	(*m).new_value = new_val;
	return new_val;
}
