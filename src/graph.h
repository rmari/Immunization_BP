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
		Edge e = { &a, &b, edgeNb() };
		
		a.addEdge(&e);
		b.addEdge(&e);
		
		edges.push_back(e);
	}

	int siteNb() const{
		return sites.size();
	}

	int edgeNb() const{
		return edges.size();
	}

};
#endif // #ifndef __Graph__
