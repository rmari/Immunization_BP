#ifndef __Hamiltonian_MP__
#define __Hamiltonian_MP__

#include "MP_algo.h"
#include "SIR_MP.h"

using namespace std;

class Graph;
class MPalgo;
class SIR_MP;

class Hamiltonian_MP: public MPalgo{

 private:
	double mu; // chemical potential
	vector <double> edgeSSEnergies;
	vector <ScalarMessage> messages_weighted;
	SIR_MP *SIRMP;

 public:
	
	Hamiltonian_MP(const Graph &gr, SIR_MP *SIR);
	~Hamiltonian_MP();

	virtual double MP_iteration(vector<ScalarMessage>::iterator m);
	virtual void exportFields(vector<double>*);
	void buildInteractionsFromSIR();
	void weightMessages();
};
#endif // #ifndef __Hamiltonian_MP__
