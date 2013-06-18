#include "Hamiltonian_MP.h"

// The Hamiltonian Message Passing iteration. 
// This is a method to modify for each problem (immunization, spreading, etc)
double
Hamiltonian_MP::MP_iteration(vector<ScalarMessage>::iterator m){ 
	return 0;
}

void
Hamiltonian_MP::exportFields(vector<double> fields){

}

Hamiltonian_MP::Hamiltonian_MP(const Graph &gr) : MPalgo(gr) {
}
Hamiltonian_MP::~Hamiltonian_MP(){
}
