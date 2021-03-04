#include "graph.h"
#include <cstdlib>
#include <time.h>

Edge::Edge(ui _id,sui _cost,Vertex* _from,Vertex* _to):id(_id),cost(_cost),from(_from),to(_to){}

Graph::Graph(ui N,f density,ui delta):vertices(N){
	srand(time(0));
	ui e = 0;
	for(ui i=0;i<N;i++){
		vertices[i].id=i;
		for(ui j=0;j<N;j++)
		if(i!=j)
		if(!delta || (delta && abs((int)(i-j))<=delta))
		if(static_cast<float>(rand())/static_cast<float>(RAND_MAX)<density)
		edges.push_back(Edge(e++,rand()%MAX_COST,&vertices[i],&vertices[j]));
	}
	for(ui i=0;i<edges.size();i++)
	edges[i].from->edges.push_back(&edges[i]);
}
