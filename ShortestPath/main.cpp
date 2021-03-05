#include "graph.h"
#include "dijkstra.h"
#include "bellman_ford.h"
#include "moore.h"

#include <chrono>
#include <iostream>

#define DIJKSTRA 0
#define BELLMAN_FORD 1
#define MOORE 2

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
void run_tool(const sui i,const Graph& g,const ui s);
ui time_tool(const ui i,const Graph& g,const ui s);

int main(int argc, char**argv){
	run_benchmarks();
}

void run_benchmarks(){
	cout<<"delta,density,|V|,|E|,dijkstra,bellman_ford,moore"<<endl;
	for(auto c:configs){
		Graph g(c.size,c.density,c.delta);
		cout<<c.delta<<","<<c.density<<","<<c.size<<","<<g.edges.size()<<",";
		for(sui i=0; i<3; i++){
			cout<<time_tool(i,g,0);
			if(i<2)cout<<",";
		}
		cout<<endl;
	}
}

ui time_tool(const ui i,const Graph& g,const ui s){
	auto t1 = high_resolution_clock::now();
	run_tool(i,g,s);
    	auto t2 = high_resolution_clock::now();
    	return (duration_cast<milliseconds>(t2 - t1)).count();
}

void run_tool(const sui i,const Graph& g,const ui s){
	if(i==DIJKSTRA)dijkstra(g,s);
	else if(i==BELLMAN_FORD)bellman_ford(g,s);
	else if(i==MOORE)moore(g,s);
}
