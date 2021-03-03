#include "ford_fulkerson.h"
#include "graph.h"

#include <vector>
#include <iostream>

FordFulkerson::FordFulkerson(Graph* _g,const ui _s,const ui _t):g(_g),s(_s),t(_t),x(_g->edges.size(),0){}

void FordFulkerson::run(){
	while(compute_path()){
		sui delta = 255;
		for(ui i=0; i<path.size();i++)
			if(path_dir[i] && path[i]->u-x[path[i]->id]<delta)
				delta = path[i]->u-x[path[i]->id];
			else if(!path_dir[i] && x[path[i]->id]<delta)
				delta = x[path[i]->id];
		for(ui i=0; i<path.size();i++)
			if(path_dir[i])
				x[path[i]->id] -= delta;
			else
				x[path[i]->id] += delta;
	}
}
