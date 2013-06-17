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
	
	void addSite(int sitename){
		Site s = Site(sitename);
		sites.push_back(s);
	}

	void addEdge(Site &a, Site &b){
		Edge e = { &a, &b };
		
		a.addEdge(&e);
		b.addEdge(&e);

		edges.push_back(e);
	}


};
#endif // #ifndef __Graph__
