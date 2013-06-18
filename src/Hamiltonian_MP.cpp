#include <math.h>
#include "Hamiltonian_MP.h"

// The Hamiltonian Message Passing iteration. 
// This is a method to modify for each problem (immunization, spreading, etc)

double
Hamiltonian_MP::MP_iteration(vector<ScalarMessage>::iterator m){ 
	// eq (19) in the notes. Right now, this is written for the spreading problem 

	double new_value = 0;

	for(vector<ScalarMessage*>::iterator master = (*m).master_messages.begin(); master != (*m).master_messages.end(); master++){
		new_value += (*master)->value;
	}
	new_value /= (2*mu);
	new_value -= 0.5;
	
	(*m).new_value=new_value;

	return new_value;
}

void
Hamiltonian_MP::exportFields(vector<double> *fields){
	// eq (20) in the notes. Right now, this is written for the spreading problem 

	for(int i=0; i<g->siteNb(); i++)
		(*fields)[i] = 0;

	for(vector<ScalarMessage>::iterator m = messages.begin(); m != messages.end(); m++){
		int j = (*m).slave_site->name;
		(*fields)[j] += (*m).value;
	}

	for(int i=0; i<g->siteNb(); i++){
		(*fields)[i] /= (2*mu);
		(*fields)[i] -= 0.5;
	}
	
}

void 
Hamiltonian_MP::buildInteractionsFromSIR(){

	for(vector<double>::iterator e=edgeSSEnergies.begin(); e != edgeSSEnergies.end(); e++)
		(*e)=0;

	for(vector<ScalarMessage>::iterator m = SIRMP->messages.begin(); m != SIRMP->messages.end(); m++){
		int i = (*m).edge->name;
		edgeSSEnergies[i] += log ( 1 - SIRMP->w*( 1 - (*m).value ) );
	}
	   
}


void
Hamiltonian_MP::weightMessages(){
	// eq. (19) : if parallel update (!), 
	// each message can be associated to to a "weighted" (by Exp(-beta E_ij)) message,
	// and eq. (19) becomes simply 
	// 2mu h = -mu + \sum weighted_messages
	//	
	// as those weighted messages are used many times (on average <z>-1 times), 
	// we precompute them.
	//
	//
	// Technically, for optimization, 
	// we overwrite each message value by its weighted message,
	// as the initial value of the message is not used any more.
	// This is only valid if the updating is parallel.


	double edgeSTEnergies = SIRMP->log_1mw;

	for(vector<ScalarMessage>::iterator m = messages.begin(); m != messages.end(); m++){
		//		for(vector<ScalarMessage>::iterator master=(*m).master_messages
		int i = (*m).edge->name;
		(*m).value = max( edgeSTEnergies, mu*(*m).value ) - max( edgeSSEnergies[i], edgeSTEnergies + mu*(*m).value);
	}

}


Hamiltonian_MP::Hamiltonian_MP(const Graph &gr, SIR_MP *SIR) : MPalgo(gr) {
	SIRMP = SIR;

	edgeSSEnergies.resize(g->edgeNb());
	for(int i=0; i<g->edgeNb();i++)
		edgeSSEnergies[i]=0;


	mu = -0.1;
}

Hamiltonian_MP::~Hamiltonian_MP(){
	edgeSSEnergies.clear();
}
