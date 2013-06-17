#ifndef __Graph__
#define __Graph__

#include <vector>
#include "site.h"
#include "edge.h"

using namespace std;

class Site;
struct Edge;

class Graph{

 public:
	vector <Site> sites;
	vector <Edge> edges;

	Graph(){};
	~Graph(){};

};
#endif // #ifndef __Graph__
