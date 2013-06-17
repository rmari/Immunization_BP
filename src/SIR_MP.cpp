#include "SIR_MP.h"

// The SIR Message Passing iteration. 
// This is the method to modify for each problem (immunization, spreading, etc)
void
SIR_MP::MP_iteration(iterator){
	int i = (*m).edge.master_site;
	int j = (*m).edge.slave_site;
	
	double new_val=1;
	for(auto master = (*m).master_message.begin(); master != (*m).master_message.begin(); master++){
		new_val *= (1-w*(1-(*master)));
	}
	(*m).new_value = new_val;
	
}
