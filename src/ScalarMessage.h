#ifndef __ScalarMessage__
#define __ScalarMessage__

struct Edge;

classe ScalarMessage{
 public:

	struct Edge *edge;
	double value;
	double new_value;

	int master_site;
	int slave_site;

	array <ScalarMessage*> master_messages;

	ScalarMessage(bool updown){
		if(updown){
			master_site = e->site1;
			slave_site  = e->site2;
		}else{
			master_site = e->site2;
			slave_site  = e->site1;
		}
	}

	~ScalarMessage(){};

	addMasters(ScalarMessage* m){
		master_messages.push_back(m);
	}

};
#endif // #ifndef __ScalarMessage__
