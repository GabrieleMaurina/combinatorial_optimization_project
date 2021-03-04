#include "dijkstra.h"
#include "graph.h"
#include "ford_fulkerson.h"

#include <queue>

bool Dijkstra::compute_path(){
	path.clear();
	path_dir.clear();
	queue<ui> q;
	vector<bool> visited(g->vertices.size(),false);
	vector<ui> pred(g->vertices.size());
	vector<bool> dir(g->vertices.size());
	q.push(s);
	visited[s] = true;
	while(!q.empty()){
		ui i = q.front();
		q.pop();
		if(i==t){
			while(i!=s){
				path.push_back(&g->edges[pred[i]]);
				path_dir.push_back(dir[i]);
				if(dir[i]) i = g->edges[pred[i]].from->id;
				else i = g->edges[pred[i]].to->id;
			}
			return true;
		}
		for(auto e:g->vertices[i].out_edges)
			if(!visited[e->to->id])
			if(e->u-x[e->id]>0){
				visited[e->to->id] = true;
				q.push(e->to->id);
				pred[e->to->id] = e->id;
				dir[e->to->id] = true;

			}
		for(auto e:g->vertices[i].in_edges)
			if(!visited[e->from->id])
			if(x[e->id]>0){
				visited[e->from->id] = true;
				q.push(e->from->id);
				pred[e->from->id] = e->id;
				dir[e->from->id] = false;
			}
	}
	return false;
}
