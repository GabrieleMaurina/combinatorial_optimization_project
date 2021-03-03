#include "dijikstra.h"
#include "graph.h"

#include <vector>

void ford_fulkerson(const Graph& g,const ui s,const ui t){
	/*const ui N = g.vertices.size();
	vector<ui> cost(N,INF);
	vector<ui> pred(N,s);
	vector<bool> flag(N,false);
	cost[s] = 0;
	for(ui i=0;i<N;i++){
		ui cmin = INF;
		ui idmin = 0;
		for(ui j=0;j<N;j++)
		if(!flag[j]&&cost[j]<cmin){
			idmin = j;
			cmin = cost[j];
		}
		flag[idmin] = true;
		for(auto e:g.vertices[idmin].edges)
		if(!flag[e->to->id])
		if(cost[idmin]+e->cost<cost[e->to->id]){
			cost[e->to->id] = cost[idmin]+e->cost;
			pred[e->to->id] = idmin;
		}
	}*/
}
