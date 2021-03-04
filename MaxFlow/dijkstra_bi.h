#ifndef DIJKSTRA_BI_H
#define DIJKSTRA_BI_H

#include "ford_fulkerson.h"

struct DijkstraBi:FordFulkerson{
	using FordFulkerson::FordFulkerson;
	bool compute_path();
	void reconstruct_path(ui i,vector<ui>& ps,vector<ui>& pd,vector<bool>& ds,vector<bool>& dt);
};

#endif
