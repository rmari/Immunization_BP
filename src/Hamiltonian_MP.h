#ifndef __Hamiltonian_MP__
#define __Hamiltonian_MP__

#include <array>

using namespace std;

class Graph;
class MPalgo;

class Hamiltonian_MP: public MPalgo{

 private:

 public:
	
 Hamiltonian_MP(const Graph &gr) : MPalgo(gr) {};
	~Hamiltonian_MP(){};

	virtual double MP_iteration(iterator);


};
#endif // #ifndef __Hamiltonian_MP__
