#ifndef __MPalgo__
#define __MPalgo__

#include <array>

using namespace std;

class Graph;

class MPalgo{

 private:
	Graph *g;

	int *gconf;

	array <ScalarMessage> messages;
	array <ScalarMessage> new_messages;

 public:
	
	void iterate();

};
#endif // #ifndef __MPalgo__
