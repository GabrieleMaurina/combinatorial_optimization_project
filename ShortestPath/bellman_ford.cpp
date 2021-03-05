#include "bellman_ford.h"
#include "graph.h"

#include <vector>

void bellman_ford(const Graph& g,const ui s){
	const ui N = g.vertices.size();
	vector<ui> cost(N,INF);
	vector<ui> pred(N,s);
	cost[s] = 0;
	for(ui i=1;i<N;i++)
	for(auto e:g.edges)
	if(cost[e.from->id]+e.cost<cost[e.to->id]){
		cost[e.to->id] = cost[e.from->id]+e.cost;
		pred[e.to->id] = e.from->id;
	}
}
