#include <iostream>
#include <cstdlib>
#include <unordered_set>
#include "Graph.h"
#include "Files.h"
#include "Algo.h"

using namespace std;

int main() {

    try {
        Graph g;
        Files F;

        bool done = F.displayGraphsFiles();

        if (done) {
            cout << "do you want to modify saved graph? 'type 'y' for yes': ";
            char s;
            cin >> s;
            cout << endl;
            if (tolower(s) == 'y') {
                cout << "\n\nyour choice: ";
                int choice; cin >> choice;
                g = F.readGraphFromFile(choice);
            }
            else {
                char sh;
                cout << "\nEnter the type of the graph (d for directed || u for undirected): ";
                cin >> sh;
                g.setGraphTypeByChar(sh);
            }
        }
        else {
            char sh;
            cout << "\nEnter the type of the graph (d for directed || u for undirected): ";
            cin >> sh;
            g.setGraphTypeByChar(sh);
        }

        int choice;

        do {
            cout << "1-Add\n2-Display\n3-Update\n4-Delete\n5-Shortest path\n6-Save the graph\n0-Exit\nyour choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                int res;
                do {

                    cout << "\n1-Add vertices\n2-Add edges\n0-Back\nenter number of the operation: ";
                    cin >> res;
                    switch (res)
                    {
                    case 1: {
                        int num;
                        cout << "Enter number of vertices:\n";
                        cin >> num;
                        while (num != 0) {
                            cout << "\nEnter the name of the vertex:";
                            string name; cin >> name;
                            if (g.vertexExist(name)) {
                                cout << "\nThis vertex already exists" << endl;
                            }
                            else {
                                g.addVertex(name);
                                //cout << "Vertex added successfully" << endl;
                            }
                            --num;
                        }
                        break;
                    }
                    case 2: {
                        int num;
                        cout << "Enter number of edges:\n";
                        cin >> num;
                        while (num != 0) {
                            cout << "Enter the source name: ";
                            string source; cin >> source;
                            cout << "\nEnter the destination name: ";
                            string dest; cin >> dest;
                            cout << "\nEnter the weight: ";
                            int weight; cin >> weight;
                            g.addEdge(source, dest, weight);
                            --num;
                        }
                        break;
                    }
                    }
                    cout << "\n-----------------------------------------------------------\n";
                } while (res != 0);
                break;
            }
            case 2: {
                int res;
                do {
                    cout << "\n1-Show vertices\n2-Show edges\n0-Back\nenter number of the operation: ";
                    cin >> res;
                    switch (res)
                    {
                    case 1: {
                        g.showVertices();
                        break;
                    }
                    case 2: {
                        g.showEdges();
                        break;
                    }
                    }
                    cout << "\n-----------------------------------------------------------\n";
                } while (res != 0);
                break;
            }
            case 3: {
                int res;
                do {
                    cout << "\n1-update vertex name\n2-update edge weight\n0-Back\nenter number of the operation: ";
                    cin >> res;
                    switch (res)
                    {
                    case 1: {
                        cout << "Enter the name of the vertex you would like to modify its name: ";
                        string name; cin >> name;
                        cout << "\nEnter the new name: ";
                        string newName; cin >> newName;
                        g.updateVertex(name, newName);
                        break;
                    }
                    case 2: {
                        cout << "Enter the source name: ";
                        string source; cin >> source;
                        cout << "\nEnter the destination name: ";
                        string dest; cin >> dest;
                        cout << "\nEnter the old weight: ";
                        int weight2; cin >> weight2;
                        cout << "\nEnter the new weight: ";
                        int weight; cin >> weight;
                        g.updateEdge(source, dest, weight2, weight);
                        break;
                    }
                    }
                    cout << "\n-----------------------------------------------------------\n";
                } while (res != 0);
                break;
            }
            case 4: {
                int res;
                do {
                    cout << "\n1-Delete vertex\n2-Delete edge\n3-Delete graph\n0-Back\nenter number of the operation: ";
                    cin >> res;
                    switch (res)
                    {
                    case 1: {
                        cout << "Enter the name of the vertex: ";
                        string name; cin >> name;
                        g.deleteVertex(name);
                        break;
                    }
                    case 2: {
                        cout << "Enter the source name: ";
                        string source; cin >> source;
                        cout << "\nEnter the destination name: ";
                        string dest; cin >> dest;
                        cout << "\nEnter the weight: ";
                        int weight; cin >> weight;
                        g.deleteEdge(source, dest, weight);
                        break;
                    }
                    case 3: {
                        string sure;
                        cout << "Are you sure you want to delete the graph (Y / n)?" << endl;
                        cin >> sure;
                        if (sure == "Y") {
                            g.deleteGraph();
                        }
                        break;
                    }
                    }
                    cout << "\n-----------------------------------------------------------\n";
                } while (res != 0);
                break;
            }
            case 5: {
                Algo A(g);
                cout << "\nEnter The Source City: ";
                string source;
                cin >> source;
                cout << '\n';
                cout << "Enter Destination City: ";
                string destination;
                cin >> destination;

                if (source == destination)
                {
                    cout << "The Path From a City To The Same City Costs 0 \n";
                    break;
                }
                cout << "\nplease choose which algo you want to show path using it :\n1 - Dijkstra if you're haven't negative edges\n2 - shortest path faster algo to all kinds of graphs\n";
                char c;
                cin >> c;
                if (c == '1')
                {
                    A.dijkstra(source, destination);
                    continue;
                }
                else if (c == '2')
                {
                    A.spfa(source, destination);
                    continue;
                }
                else if (c == '0')break;
                else
                {
                    cout << "Please Enter A Valid Input \n\n";
                    continue;
                }
                break;
            }
            case 6: {
                Files F(g);
                F.saveGraphFileName();
                return 0;
                break;
            }
            }
        } while (choice != 0);
    }
    catch (exception e) {
        cout << "error: " << e.what() << endl;
    }

    return 0;
}
