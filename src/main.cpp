#include <iostream>
#include "graph.h"
#include "SIR_MP.h"
#include "Hamiltonian_MP.h"

int main(int argc, const char * argv[])
{

	Graph graph;
	SIR_MP *SIR = new SIR_MP(graph);
	Hamiltonian_MP *Spreading_MP = new Hamiltonian_MP(graph, SIR);

}
