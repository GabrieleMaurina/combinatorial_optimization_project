#include "moore.h"
#include "moore_fifo_queue.h"
#include "graph.h"

#include <vector>

void moore(const Graph& g,const ui s){
	const ui N = g.vertices.size();
	vector<ui> cost(N,INF);
	vector<ui> pred(N,s);
	cost[s] = 0;
	MooreFifoQueue q;
	q.push(s);
	while(!q.empty()){
		ui i = q.pop();
		for(auto e:g.vertices[i].edges)
		if(cost[i]+e->cost<cost[e->to->id]){
			cost[e->to->id] = cost[i]+e->cost;
			pred[e->to->id] = i;
			if(!q.contains(e->to->id))
			q.push(e->to->id);
		}
	}
}
