#include "Graph.h"
#include <unordered_map>
#include <fstream>
#include <string>
#include <queue>
#include <climits>
#include <sstream>
#include <algorithm>
#include <iostream>

#define filePath "D:\\ds2\\data-structure\\DataStructure\\storedgraphs\\" //changeable


//// Constructor
Graph::Graph() {
	this->id = getGraphIDFromfile();
	this->isDirected = true;
    string fileName = "";
    bool fromFile = false;
}
////////////////


//// Getters
int Graph::getGraphId() {
	return id;
}

string Graph::getName() {
    return this->name;
}

bool Graph::getGraphType() {
    return this->isDirected;
}

string Graph::getFileName() {
    return this->fileName;
}
bool Graph::getFromFile() {
    return this->fromFile;
}

////////////////


//// Setters
void Graph::setId(int id) {
    this->id = id;
}
void Graph::setFileName(string filename) {
    this->fileName = filename;
};
void Graph::setFromFile(bool t) {
    this->fromFile = t;
}

void Graph::setGraphTypeByChar(char c) {
	
    if (toupper(c) == 'D')
        this->isDirected = true;
    else if (toupper(c) == 'U')
        this->isDirected = false;
    else
        cout << "\ninvalid character";
}

////////////////


//// Checkers
bool Graph::vertexExist(string name) {
    return graph.count(name) != 0;
}
bool Graph::edgeExist(string source, string destination,int weight) {

    pair<string, int> p = { destination, weight };
    return count(graph.at(source).begin(),graph.at(source).end(), p);

}

//// Create
void Graph::addVertex(string city) {

    list<pair<string, int>>e;
    graph.insert({ city, e });
};

void Graph::addEdge(string source, string destination, int weight)
{
    if (vertexExist(source) && vertexExist(destination))
    {
        if (!edgeExist(source, destination,weight))
        {   
            graph.at(source).push_back({ destination, weight });
            if(!isDirected)
            {
                graph.at(destination).push_back({ source, weight });
            }    
        }
        else {
            cout << "that edge is already exist";
        }
        
    }
    else {
        cout << "double check the cities' name";
    }

}


////////////////


//// display
void Graph::showVertices() {
    cout << "\nAll cities:\n";
    for (auto x: graph) {
        cout << x.first << endl;
    }
}
void Graph::showEdges() {
    cout << "\nAll Elements : \n";
    for (auto x: graph)
    {
        for (auto it = x.second.begin(); it != x.second.end(); ++it) {
            cout << x.first << " --> " << it->first << ", weight: " << it->second << endl;
        }
    }
}
////////////////


//// Update
void Graph::updateVertex(string name, string newName) {
    if (vertexExist(name)) {
        if (vertexExist(newName)) {
            cout << "the name of this vertex is already exist try again" << endl;
            string  u;
            cout << "new name: ";
            cin >> u;
            updateVertex(name, u);
        }
        else {
            auto* temp = new list<pair<string, int>>();
            *temp = graph[name];
            graph.erase(name);
            graph.insert({ newName, *temp });
            for (auto x : graph)
            {
                for (auto it = x.second.begin(); it != x.second.end(); ++it) {
                    if (it->first == name) {
                        int v = it->second;
                        graph.at(x.first).remove({ name,it->second });
                        graph.at(x.first).push_back({ newName,v });
                    }
                    
                }

            }
            cout << "done" << endl;
        }
    }
    else {
        cout << "City doesn't exist!" << endl;
    }
}
void Graph::updateEdge(string source, string destination, int oldWeight,int newWeight)
{
    try{
        if (!edgeExist(source, destination, oldWeight)) {
            cout << "Edge between " << source << " and " << destination << " does not exist." << '\n';
        }
        else {
            deleteEdge(source, destination, oldWeight);
            addEdge(source, destination, newWeight);
            system("cls");
            cout << "updateed successfully" << endl;
        }
    }catch (exception e){
        cout << "something went wrong: " << e.what();
    }
}
////////////////


//// Delete
void Graph::deleteEdge(string source, string destination,int  weight) {
    try{
        if (!edgeExist(source, destination, weight)) {
            cout << "Edge between " << source << " and " << destination << " does not exist." << '\n';
        }else {
                graph.at(source).remove({ destination,weight });
                if (!isDirected) {
                    graph.at(destination).remove({ source,weight });
                }
            cout << "Edges deleted successfully" << endl;
        }
    }catch (exception e){
        cout << "something went wrong: " << e.what();
    }
}

void Graph::deleteVertex(string name) {

    if (vertexExist(name)) {
        graph.erase(name);
        for (auto x : graph) {
            for (auto it = x.second.begin(); it != x.second.end(); ++it) {
                if (it->first == name)
                {
                    graph.at(x.first).remove({ name,it->second });
                }
            }
        }
        cout << "City deleted successfully!" << endl;
    }
    else {
        cout << "This city doesn't exist!" << endl;
    }
}
void Graph::deleteGraph()
{          
    graph.clear();
    cout << "deleted successfully!" << endl;
}
////////////////

//get graph ID
int  getGraphIDFromfile() {
    int count = 0;
    ifstream grraph("storedGraphs.txt", ios::out);
    string line;
    if (grraph.is_open()) {
        while (grraph)
        {
            grraph >> line;
            count++;
        }
    }
    if (count == 0)
        return 1;
    else
        return count;
}