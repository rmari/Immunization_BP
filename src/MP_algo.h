#ifndef __MPalgo__
#define __MPalgo__

#include <array>

using namespace std;

class Graph;

class MPalgo{
	/* 
	   This class should be an generic class which gathers 
	   as many generic features as possible, so that we can treat
	   the SIR Message Passing and the real spreading/immunization Message Passing
	   with high similarity.
	   Hence, the two classes SIR_MP, and hamiltonianMP (?) inherit from this one.
	*/

 private:
	Graph *g;

	int *gconf;

	array <ScalarMessage> messages;
	array <ScalarMessage> new_messages;

 public:
	
	void iterate();

};
#endif // #ifndef __MPalgo__
