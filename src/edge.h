#ifndef __Immunization_BP_Edge__
#define __Immunization_BP_Edge__

#include <vector>

using namespace std;

class VariableSite;

class Edge{
 private:
	double message_1to2;
	double old_message_1to2;
	double message_2to1;
	double old_message_2to1;

	double P_1to2;
	double old_P_1to2;
	double P_2to1;
	double old_P_2to1;

 public:
    VariableSite *site1;
    VariableSite *site2;

	double message_1to2(){
		return message_1to2;
	}
	void message_1to2(double newmessage_1to2){
		old_message_1to2=message_1to2;
		message_1to2 = newmessage_1to2;
	}

	double message_2to1(){
		return message_2to1;
	}
	void message_2to1(double newmessage_2to1){
		old_message_2to1=message_2to1;
		message_2to1 = newmessage_2to1;
	}


	double P_1to2(){
		return P_1to2;
	}
	void P_1to2(double newP_1to2){
		old_P_1to2=P_1to2;
		P_1to2 = newP_1to2;
	}

	double P_2to1(){
		return P_2to1;
	}
	void P_2to1(double newP_2to1){
		old_P_2to1=P_2to1;
		P_2to1 = newP_2to1;
	}

	double rel_message_1to2(){
		return (message_1to2-old_message_1to2)/(message_1to2+old_message_1to2);
	}

	double rel_message_2to1(){
		return (message_2to1-old_message_2to1)/(message_2to1+old_message_2to1);
	}

	double rel_message_1to2(){
		return (message_1to2-old_message_1to2)/(message_1to2+old_message_1to2);
	}

	double rel_message_2to1(){
		return (message_2to1-old_message_2to1)/(message_2to1+old_message_2to1);
	}


	double rel_P_1to2(){
		return (P_1to2-old_P_1to2)/(P_1to2+old_P_1to2);
	}

	double rel_P_2to1(){
		return (P_2to1-old_P_2to1)/(P_2to1+old_P_2to1);
	}

	double rel_P_1to2(){
		return (P_1to2-old_P_1to2)/(P_1to2+old_P_1to2);
	}

	double rel_P_2to1(){
		return (P_2to1-old_P_2to1)/(P_2to1+old_P_2to1);
	}

};
#endif // #ifndef __Immunization_BP_Edge__


