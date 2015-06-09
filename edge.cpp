#include "edge.hpp"



Vertex Edge::other(const Vertex vertex) const {
	if (vertex == v){
		return w;
	}
	else{
		return v;
	}	
}
