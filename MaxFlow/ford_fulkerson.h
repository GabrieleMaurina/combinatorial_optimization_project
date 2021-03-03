#ifndef DIJIKSTRA_H
#define DIJIKSTRA_H

#include "graph.h"

#include <vector>

using namespace std;

struct FordFulkerson{
	Graph* g;
	const ui s;
	const ui t;
	FordFulkerson(Graph* _g,const ui _s,const ui _t);
	void run();
	virtual bool compute_path() = 0;
	vector<sui> x;
	vector<Edge*> path;
	vector<bool> path_dir;
};

#endif
