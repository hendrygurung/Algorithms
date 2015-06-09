#include "union_find.hpp"



Union_Find::Union_Find(unsigned long int N){
	for (unsigned long int count = 0; count < N; count++){
		id.push_back(count);
	
		sz.push_back(count);
	}
}

Component Union_Find::find (const Site p){
	Site h = p;
	
	while (h != id[h]){
		id[h] = id[id[h]];
		h = id[h];
	}
	
	return h;
}


void Union_Find::onion (const Site p, const Site q){
	unsigned long int i = find(p);
	
	unsigned long int j = find(q);
	
	if (i==j){
		return;
	}
	
	if (sz[i] < sz[j]){
		id[i] = j;
		sz[j] += sz[i];
	}
	
	else if (sz[i] > sz[j]){
		id[j] = i;
		sz[i] += sz[j];
	} 

}
