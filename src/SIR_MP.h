#ifndef __SIR_MP__
#define __SIR_MP__

#include "graph.h"
#include "MP_algo.h"

using namespace std;

class Graph;
class MPalgo;

class SIR_MP: public MPalgo{

 private:

 public:
	
	SIR_MP(const Graph &gr) : MPalgo(gr) {};
	~SIR_MP(){};

	virtual double MP_iteration(vector<ScalarMessage>::iterator m);

};
#endif // #ifndef __SIR_MP__
