#ifndef __Immunization_BP_VariableSite__
#define __Immunization_BP_VariableSite__

#include <vector>

using namespace std;

class Edge;

class VariableSite{
 private:
	double field;
	double old_field;


 public:
	vector <Edge*> edges;
	int name;

	VariableSite(int sname){
		name=sname;
		field=0;
		old_field=0;
	}

	double field(){
		return field;
	}
	void field(double newfield){
		old_field=field;
		field = newfield;
	}

	double relative_step(){
		return (field-old_field)/(field+old_field);
	}
	
};
#endif // #ifndef __Immunization_BP_VariableSite__


