#pragma once
#include <unordered_map>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <stack>
using namespace std;

class Graph
{
private:
	int id;
    string name;
    string fileName;
	bool isDirected;
    bool fromFile = false;

public:

    //// Constructor
    Graph();
    ////////////////

    unordered_map<string, list<pair<string,int>>> graph;
    //// Getters
    int getGraphId();
    string getName();
    bool getGraphType();
    string getFileName();
    bool getFromFile();

    //// Setters
    void setId(int id);
    void setGraphTypeByChar(char type);
    void setFileName(string name);
    void setFromFile(bool t);


    //// Checker
    bool vertexExist(string name);
    bool edgeExist(string source, string destination,int weight);

    //// Create
    void addVertex(string v);
    void addEdge(string sourceName, string destName, int weight);
    ////////////////

    //// Read
    void showVertices();
    void showEdges();
    ////////////////

    //// Update
    void updateVertex(string name, string newName);
    void updateEdge(string source, string destination, int weight, int weight2);
    ////////////////

    //// Delete
    void deleteEdge(string source, string destination,int weight);
    void deleteVertex(string name);
    void deleteGraph();
};
//id
int getGraphIDFromfile();

