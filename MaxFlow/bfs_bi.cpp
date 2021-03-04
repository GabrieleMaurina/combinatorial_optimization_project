#include "bfs_bi.h"
#include "graph.h"

#include <queue>

bool BfsBi::compute_path(){
	path.clear();
	path_dir.clear();
	queue<ui> qs;
	queue<ui> qt;
	vector<bool> vs(g->vertices.size(),false);
	vector<bool> vt(g->vertices.size(),false);
	vector<ui> ps(g->vertices.size());
	vector<ui> pt(g->vertices.size());
	vector<bool> ds(g->vertices.size());
	vector<bool> dt(g->vertices.size());
	qs.push(s);
	qt.push(t);
	vs[s] = true;
	vt[t] = true;
	while(!qs.empty()&&!qt.empty()){
		ui is = qs.front();
		ui it = qt.front();
		qs.pop();
		qt.pop();
		if(vt[is]){
			reconstruct_path(is,ps,pt,ds,dt);
			return true;
		}
		if(vs[it]){
			reconstruct_path(it,ps,pt,ds,dt);
			return true;
		}
		for(auto e:g->vertices[is].out_edges)
			if(!vs[e->to->id])
			if(e->u-x[e->id]>0){
				vs[e->to->id] = true;
				qs.push(e->to->id);
				ps[e->to->id] = e->id;
				ds[e->to->id] = true;

			}
		for(auto e:g->vertices[is].in_edges)
			if(!vs[e->from->id])
			if(x[e->id]>0){
				vs[e->from->id] = true;
				qs.push(e->from->id);
				ps[e->from->id] = e->id;
				ds[e->from->id] = false;
			}
		for(auto e:g->vertices[it].out_edges)
			if(!vt[e->to->id])
			if(x[e->id]>0){
				vt[e->to->id] = true;
				qt.push(e->to->id);
				pt[e->to->id] = e->id;
				dt[e->to->id] = false;
			}
		for(auto e:g->vertices[it].in_edges)
			if(!vt[e->from->id])
			if(e->u-x[e->id]>0){
				vt[e->from->id] = true;
				qt.push(e->from->id);
				pt[e->from->id] = e->id;
				dt[e->from->id] = true;
			}
	}
	return false;
}

void BfsBi::reconstruct_path(ui i,vector<ui>& ps,vector<ui>& pt,vector<bool>& ds,vector<bool>& dt){
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
