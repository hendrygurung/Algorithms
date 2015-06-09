#include "graph.hpp"
#include "union_find.hpp"
#include <algorithm>
#include <queue>

using namespace std;

Weighted_Graph::Weighted_Graph(string name){
	E = 0;
	V = 0;

}

void Weighted_Graph::add_edge(const Edge &e){
	Vertex x = e.either();
	Vertex y = e.other(x);
	
	int xinadj = 0;
	int yinadj = 0;

	for (int i = 0; i < adj.size(); i++){

		if (x == adj[i].front()) {
			adj[i].push_back(y);
			xinadj = 1;
		}

		if (y == adj[i].front()) {
			adj[i].push_back(x);
			yinadj = 1;
		}
	}

	if (xinadj == 0) {
		list<Vertex> newnew;
		newnew.push_back(x);
		newnew.push_back(y);
		adj.push_back(newnew);
		V++; 

	}

	if (yinadj == 0) {
		list<Vertex> newnew;
		newnew.push_back(y);
		newnew.push_back(x);
		adj.push_back(newnew);
		V++; 
	}
	E++;
	edges.push_back(e);
}

MST Weighted_Graph::kruskal(string name) const{
	auto que = [](Edge x, Edge y){
		return x.weight() > y.weight();
	};
	
	typedef priority_queue<Edge, vector<Edge>, decltype(que)> que2;

	que2 SD(que);
	
	MST reddit;
	
	Union_Find tree(num_vertices());
	
	int i = 0;
	
	for(i = 0; i < E; i++){
		SD.push(edges[i]);
	}

	while (reddit.size() < num_vertices() - 1){
		Edge indv = SD.top();
		SD.pop();
		Vertex x = indv.either(), y = indv.other(x);
	
		if (tree.connected(x,y)){
			continue;
		}
	
		tree.onion(x,y);
		reddit.add_edge(indv);

	}
	return reddit;

}





