#ifndef BFS_H
#define BFS_H

#include "ford_fulkerson.h"

struct Bfs:FordFulkerson{
	using FordFulkerson::FordFulkerson;
	bool compute_path();
};

#endif
