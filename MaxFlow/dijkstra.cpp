#include "dijkstra.h"
#include "graph.h"
#include "ford_fulkerson.h"

#include <queue>

bool Dijkstra::compute_path(){
	path.clear();
	path_dir.clear();
	priority_queue<pair<sui,ui>> q;
	vector<sui> c(g->vertices.size(),0);
	vector<ui> pred(g->vertices.size());
	vector<bool> dir(g->vertices.size());
	q.push({MAX_CAPACITY,s});
	c[s] = MAX_CAPACITY;
	while(!q.empty()){
		sui ci = q.top().first;
		sui i = q.top().second;
		q.pop();
		if(ci<c[i]) continue;
		if(i==t){
			while(i!=s){
				path.push_back(&g->edges[pred[i]]);
				path_dir.push_back(dir[i]);
				if(dir[i]) i = g->edges[pred[i]].from->id;
				else i = g->edges[pred[i]].to->id;
			}
			return true;
		}
		for(auto e:g->vertices[i].out_edges){
			sui ec = e->u-x[e->id];
			sui nc = min(ec,c[i]);
			if(nc>c[e->to->id]){
				c[e->to->id]=nc;
				q.push({nc,e->to->id});
				pred[e->to->id] = e->id;
				dir[e->to->id] = true;

			}
		}
		for(auto e:g->vertices[i].in_edges){
			sui ec = x[e->id];
			sui nc = min(ec,c[i]);
			if(nc>c[e->from->id]){
				c[e->from->id]=nc;
				q.push({nc,e->from->id});
				pred[e->from->id] = e->id;
				dir[e->from->id] = false;
			}
		}
	}
	return false;
}
