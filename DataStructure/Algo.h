#pragma once
#include "Graph.h"
class Algo
{
	Graph g;
public:
	Algo(Graph g);
	void dijkstra(string source, string destination);
	void spfa(string source, string destination);
	void bellmanFord(string source, string destination);
};

