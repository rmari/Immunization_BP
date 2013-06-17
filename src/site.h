#ifndef __Site__
#define __Site__

#include <vector>

using namespace std;

class Edge;

class Site{
 private:
	vector <Edge*> edges;
 public:

	int name;

	Site(int sname){
		name=sname;
	}

	~Site(){
		edges.clear();
	}

	void addEdge(Edge* e){
		edges.push_back(e);
	}

	vector<Edge*>::iterator edgeBegin(){
		return edges.begin();
	}
	vector<Edge*>::iterator edgeEnd(){
		return edges.end();
	}

	
};
#endif //#ifndef _Site__


