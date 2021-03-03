#ifndef MOORE_FIFO_QUEUE_H
#define MOORE_FIFO_QUEUE_H

#include "graph.h"
#include <queue>
#include <unordered_set>

using namespace std;

struct MooreFifoQueue{
	queue<ui> q;
	unordered_set<ui> us;
	void push(const ui value);
	ui pop();
	bool empty();
	bool contains(const ui value);
};

#endif
