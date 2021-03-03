#include "graph.h"
#include "bfs.h"

#include <chrono>
#include <iostream>

#define BFS 0
#define BFS_BI 1
#define DIJKSTRA 2
#define DIJKSTRA_BI 3

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

ui sizes[] = {10, 100, 1000, 2000, 3000, 4000};
f densities[] = {0.01, 0.05, 0.1};

void run_benchmarks();
void run_tool(const sui i,Graph* g,const ui s,const ui t);
ui time_tool(const ui i,Graph* g,const ui s,const ui t);

int main(int argc, char**argv){
	run_benchmarks();
}

void run_benchmarks(){
	cout<<"density,|V|,|E|,bfs,bfs_bi,dijkstra,dijkstra_bi"<<endl;
	for(auto density:densities)
	for(auto n:sizes){
		Graph g(n,density);
		cout<<density<<","<<n<<","<<g.edges.size()<<",";
		for(sui i=0; i<4; i++){
			cout<<time_tool(i,&g,0,n-1);
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
	/*else if(i==BFS_BI)BfsBi(&g,s,t);
	else if(i==DIJIKSTRA)Dijkstra(&g,s,t);
	else if(i==DIJIKSTRA_BI)DijkstraBi(&g,s,t);*/
}
