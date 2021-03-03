#include "graph.h"
#include "dijikstra.h"
#include "bellan_ford.h"
#include "moore.h"

#include <vector>
#include <chrono>
#include <iostream>

#define DIJIKSTRA 0
#define BELLAN_FORD 1
#define MOORE 2

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::milliseconds;

ui sizes[] = {1, 10, 100, 1000, 2000, 3000, 4000};
f densities[] = {0.01, 0.05, 0.1};

void run_benchmarks();
void run_tool(const sui i,const Graph& g,const ui s);
ui time_tool(const ui i,const Graph& g,const ui s);

int main(int argc, char**argv){
	run_benchmarks();
}

void run_benchmarks(){
	cout<<"density,|V|,|E|,dijikstra,bellan_ford,moore"<<endl;
	for(auto density:densities)
	for(auto n:sizes){
		const Graph g(n,density);
		cout<<density<<","<<n<<","<<g.edges.size()<<",";
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
	if(i==DIJIKSTRA)dijikstra(g,s);
	else if(i==BELLAN_FORD)bellan_ford(g,s);
	else if(i==MOORE)moore(g,s);
}
