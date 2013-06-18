#ifndef __SIR_MP__
#define __SIR_MP__

#include "MP_algo.h"

using namespace std;

class Graph;
class MPalgo;

class SIR_MP: public MPalgo{

 private:
	int *gconf;
	double w;
 public:
	
	SIR_MP(const Graph &gr);
	~SIR_MP();

	virtual double MP_iteration(vector<ScalarMessage>::iterator m);
	virtual void exportFields(vector<double>);
};
#endif // #ifndef __SIR_MP__
