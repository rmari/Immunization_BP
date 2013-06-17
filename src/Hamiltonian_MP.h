#ifndef __Hamiltonian_MP__
#define __Hamiltonian_MP__

#include <array>

using namespace std;

class Graph;
class MPalgo;

class Hamiltonian_MP: public MPalgo{

 private:
	Graph *g;
	int *gconf;

	double *messages;

 public:
	
	Hamiltonian_MP(){};
	~Hamiltonian_MP(){};

	MP_iteration(iterator);

};
#endif // #ifndef __Hamiltonian_MP__
