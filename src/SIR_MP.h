#ifndef __SIR_MP__
#define __SIR_MP__

#include <array>

using namespace std;

class Graph;
class MPalgo;

class SIR_MP: public MPalgo{

 private:
	Graph *g;
	int *gconf;

	double *messages;

 public:
	
	SIR_MP(){};
	~SIR_MP(){};

	MP_iteration(iterator);

};
#endif // #ifndef __SIR_MP__
