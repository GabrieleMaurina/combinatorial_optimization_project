#include "graph.h"
#include "bfs.h"
#include "bfs_bi.h"
#include "dijkstra.h"
#include "dijkstra_bi.h"

#include <chrono>
#include <iostream>

#define BFS 0
#define BFS_BI 1
#define DIJKSTRA 2
#define DIJKSTRA_BI 3

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

struct conf{
	ui size;
	f density;
	ui delta;
};

conf configs[] = {
	{1000, 0.01, 0},
	{2000, 0.01, 0},
	{3000, 0.01, 0},
	{4000, 0.01, 0},
	{1000, 0.05, 0},
	{2000, 0.05, 0},
	{3000, 0.05, 0},
	{4000, 0.05, 0},
	{1000, 0.1, 0},
	{2000, 0.1, 0},
	{3000, 0.1, 0},
	{4000, 0.1, 0},
	{1000, 0.8, 10},
	{2000, 0.8, 10},
	{3000, 0.8, 10},
	{4000, 0.8, 10},
	{1000, 0.8, 50},
	{2000, 0.8, 50},
	{3000, 0.8, 50},
	{4000, 0.8, 50},
	{1000, 0.8, 100},
	{2000, 0.8, 100},
	{3000, 0.8, 100},
	{4000, 0.8, 100}
};

void run_benchmarks();
void run_tool(const sui i,Graph* g,const ui s,const ui t);
ui time_tool(const ui i,Graph* g,const ui s,const ui t);

int main(int argc, char**argv){
	run_benchmarks();
}

void run_benchmarks(){
	cout<<"delta,density,|V|,|E|,bfs,bfs_bi,dijkstra,dijkstra_bi"<<endl;
	for(auto c:configs){
		Graph g(c.size,c.density,c.delta);
		cout<<c.delta<<","<<c.density<<","<<c.size<<","<<g.edges.size()<<",";
		for(sui i=0; i<4; i++){
			cout<<time_tool(i,&g,0,c.size-1);
			if(i<3)cout<<",";
		}
		cout<<endl;
	}
}

ui time_tool(const ui i,Graph* g,const ui s,const ui t){
	auto t1 = high_resolution_clock::now();
	run_tool(i,g,s,t);
	auto t2 = high_resolution_clock::now();
	return (duration_cast<milliseconds>(t2 - t1)).count();
}

void run_tool(const sui i,Graph* g,const ui s,const ui t){
	if(i==BFS)Bfs(g,s,t).run();
	else if(i==BFS_BI)BfsBi(g,s,t).run();
	else if(i==DIJKSTRA)Dijkstra(g,s,t).run();
	else if(i==DIJKSTRA_BI)DijkstraBi(g,s,t).run();
}
