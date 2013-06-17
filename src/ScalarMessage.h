#ifndef __ScalarMessage__
#define __ScalarMessage__

#include <vector>

struct Edge;
class ScalarMessage;

class ScalarMessage{
 public:

	struct Edge *edge;
	double value;
	double new_value;

	const Site *master_site;
	const Site *slave_site;

    vector<ScalarMessage*> master_messages;

	ScalarMessage(Edge *e, bool updown){
		if(updown){
			master_site = e->site1;
			slave_site  = e->site2;
		}else{
			master_site = e->site2;
			slave_site  = e->site1;
		}
	}

	~ScalarMessage(){};

	void addMaster(ScalarMessage* m){
		master_messages.push_back(m);
	}
	void setValue(){
		value = new_value;
	}

};
#endif // #ifndef __ScalarMessage__
