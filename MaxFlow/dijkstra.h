#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "ford_fulkerson.h"

struct Dijkstra:FordFulkerson{
	using FordFulkerson::FordFulkerson;
	bool compute_path();
};

#endif
