#ifndef GRAPH_H
#define GRAPH_H

/*
This graph implementation is good for low density graphs. If we wanted
to use high denisty graphs an adjacency matrix would be better. If we
wanted to use very sparse graphs (where |V| >= |E|), then storing neighbors
in a unordered set would be easier.
*/

#include <cstdint>
#include <vector>

//short unsigned int
#define sui uint8_t

//unsigned int
#define ui uint32_t
#define INF 2147483647

//float
#define f float

#define MAX_CAPACITY 100

using namespace std;

struct Edge;

struct Vertex{
	ui id;
	vector<Edge*> out_edges;
	vector<Edge*> in_edges;
};

struct Edge{
	ui id;
	sui u;
	Vertex* from;
	Vertex* to;
	Edge(ui _id,sui _u,Vertex* _from,Vertex* _to);
};

struct Graph{
	vector<Vertex> vertices;
	vector<Edge> edges;
	Graph(ui N,f density,ui delta=0);
};

#endif
