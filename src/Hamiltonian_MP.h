#ifndef __Hamiltonian_MP__
#define __Hamiltonian_MP__

#include "MP_algo.h"

using namespace std;

class Graph;
class MPalgo;

class Hamiltonian_MP: public MPalgo{

 private:

 public:
	
	Hamiltonian_MP(const Graph &gr);
	~Hamiltonian_MP();

	virtual double MP_iteration(vector<ScalarMessage>::iterator m);
	virtual void exportFields(vector<double>);

};
#endif // #ifndef __Hamiltonian_MP__
