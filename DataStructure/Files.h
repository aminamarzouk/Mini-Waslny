#pragma once
#include "Graph.h"
class Files
{
	Graph g;
public:
	Files();
	Files(Graph g);
	void saveGraphFileName();
	void storeGragh(string name);
	bool checkValidFileName(string name);
	bool  displayGraphsFiles();
	void insertFileName(string name);
	Graph readGraphFromFile(int id);
};
