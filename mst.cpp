#include "mst.hpp"



void MST::add_edge(const Edge &e){
	push_back(e);
	wt += e.weight();
}

