#ifndef FORD_FULKERSON_H
#define FORD_FULKERSON_H

#include "graph.h"

#include <vector>

using namespace std;

struct FordFulkerson{
	Graph* g;
	const ui s;
	const ui t;
	vector<sui> x;
	vector<Edge*> path;
	vector<bool> path_dir;
	FordFulkerson(Graph* _g,const ui _s,const ui _t);
	void run();
	virtual bool compute_path() = 0;
	void test();
};

#endif
