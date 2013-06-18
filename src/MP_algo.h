#ifndef __MPalgo__
#define __MPalgo__

#include <vector>

#include "graph.h"
#include "ScalarMessage.h"

using namespace std;

class Graph;
class ScalarMessage;

class MPalgo{
	/* 
	   This class should be an abstract class which gathers 
	   as many generic features as possible, so that we can treat
	   the SIR Message Passing and the real spreading/immunization Message Passing
	   with high similarity.
	   Hence, the two classes SIR_MP, and Hamiltonian_MP (?) inherit from this one.
	*/

 private:

	int iteration_nb;
	
 protected:
	const Graph *g;
	vector <ScalarMessage> messages;
	vector <ScalarMessage> new_messages;


 public:
	
	MPalgo(const Graph &gr){
		g=&gr;
		iteration_nb = 0;
	}
	~MPalgo();

	void iterate();
	virtual double MP_iteration(vector<ScalarMessage>::iterator m) = 0;
	virtual void exportFields(vector<double>) = 0;
	
};
#endif // #ifndef __MPalgo__
