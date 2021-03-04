#include "dijkstra_bi.h"
#include "graph.h"
#include "ford_fulkerson.h"

#include <queue>
#include <iostream>

bool DijkstraBi::compute_path(){
	path.clear();
	path_dir.clear();
	priority_queue<pair<sui,ui>> qs;
	priority_queue<pair<sui,ui>> qt;
	vector<sui> cs(g->vertices.size(),0);
	vector<sui> ct(g->vertices.size(),0);
	vector<bool> vs(g->vertices.size(),false);
	vector<bool> vt(g->vertices.size(),false);
	vector<ui> ps(g->vertices.size());
	vector<ui> pt(g->vertices.size());
	vector<bool> ds(g->vertices.size());
	vector<bool> dt(g->vertices.size());
	qs.push({MAX_CAPACITY,s});
	qt.push({MAX_CAPACITY,t});
	cs[s] = MAX_CAPACITY;
	ct[t] = MAX_CAPACITY;
	while(!qs.empty()&&!qt.empty()){
		sui cis = qs.top().first;
		sui is = qs.top().second;
		qs.pop();
		sui cit = qt.top().first;
		sui it = qt.top().second;
		qt.pop();
		vs[is] = true;
		vt[it] = true;

		if(vt[is]){
			reconstruct_path(is,ps,pt,ds,dt);
			return true;
		}
		if(vs[it]){
			reconstruct_path(it,ps,pt,ds,dt);
			return true;
		}

		if(cis=cs[is]){
			for(auto e:g->vertices[is].out_edges){
				sui ec = e->u-x[e->id];
				sui nc = min(ec,cs[is]);
				if(nc>cs[e->to->id]){
					cs[e->to->id]=nc;
					qs.push({nc,e->to->id});
					ps[e->to->id] = e->id;
					ds[e->to->id] = true;
				}
			}
			for(auto e:g->vertices[is].in_edges){
				sui ec = x[e->id];
				sui nc = min(ec,cs[is]);
				if(nc>cs[e->from->id]){
					cs[e->from->id]=nc;
					qs.push({nc,e->from->id});
					ps[e->from->id] = e->id;
					ds[e->from->id] = false;
				}
			}
		}
		if(cit=ct[it]){
			for(auto e:g->vertices[it].out_edges){
				sui ec = x[e->id];
				sui nc = min(ec,ct[it]);
				if(nc>ct[e->to->id]){
					ct[e->to->id]=nc;
					qt.push({nc,e->to->id});
					pt[e->to->id] = e->id;
					dt[e->to->id] = false;
				}
			}
			for(auto e:g->vertices[it].in_edges){
				sui ec = e->u-x[e->id];
				sui nc = min(ec,ct[it]);
				if(nc>ct[e->from->id]){
					ct[e->from->id]=nc;
					qt.push({nc,e->from->id});
					pt[e->from->id] = e->id;
					dt[e->from->id] = true;
				}
			}
		}
	}
	return false;
}

void DijkstraBi::reconstruct_path(ui i,vector<ui>& ps,vector<ui>& pt,vector<bool>& ds,vector<bool>& dt){
	ui is = i;
	ui it = i;
	while(is!=s){
		path.push_back(&g->edges[ps[is]]);
		path_dir.push_back(ds[is]);
		if(ds[is]) is = g->edges[ps[is]].from->id;
		else is = g->edges[ps[is]].to->id;
	}
	while(it!=t){
		path.push_back(&g->edges[pt[it]]);
		path_dir.push_back(dt[it]);
		if(dt[it]) it = g->edges[pt[it]].to->id;
		else it = g->edges[pt[it]].from->id;
	}
}
