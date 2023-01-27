#include "Files.h"
#include <fstream>

#define filePath "D:\\final2\\data-structure\\DataStructure\\storedgraphs\\" //changeable

Files::Files() {};
Files::Files(Graph graph) {
    this->g = graph;
}

void Files::saveGraphFileName() {
    if (g.getFromFile()) {
        char c;
        string fileName = g.getFileName();
        cout << "do you want to update the " << fileName << " ?";
        cin >> c;
        if (tolower(c) == 'y') {
            storeGragh(fileName);
            cout << "file updated successfully\n\n";
        }
    }
    else
    {
        string name;
        cout << "Enter the file name: ";
        cin >> name;
        name += ".txt";
        if (checkValidFileName(name))
        {
            do
            {
                cout << "it's already Exist, pleas Re-Enter the name: ";
                cin >> name;
                name += ".txt";
            } while (checkValidFileName(name));
        }
        insertFileName(name);
        storeGragh(name);
        cout << "file name: " << name << "\n\n";
    }
}

//load to files
void Files::storeGragh(string name) {
    string graphName = name;

    //store graph
    ofstream grraph(filePath + graphName);

    grraph << g.getGraphId() << endl;
    grraph << (this->g.getGraphType()? "d" : "u") << endl;
    for (auto i : g.graph) {
        if (i.second.empty())
            grraph << i.first << " -" << " -" << endl;
        else
        {
            for (auto ittr = i.second.begin(); ittr != i.second.end(); ++ittr) {
                grraph << i.first << " ";
                grraph << ittr->first << " " << ittr->second << endl;
            }
        }

        grraph << endl;
    }
    grraph.close();
}
bool Files::checkValidFileName(string name) {
    ifstream grraph("storedGraphs.txt", ios::out);
    bool found = false;
    string line;
    if (grraph.is_open()) {
        while (grraph >> line)
        {
            if (line == name)
                found = true;
        }
    }
    grraph.close();
    return found;
};

//display Existing stored graphs
bool Files::displayGraphsFiles() {
    string name; int counter = 1;
    ifstream grraph("storedGraphs.txt", ios::out);
    if (grraph.is_open()) {
        cout << "files name: " << endl;
        while (getline(grraph, name))
        {
            cout << counter << "- " << name << endl;
            ++counter;
        }
    }
    if (counter != 1) {
        return true;
    }
    else {
        cout << "\nthere is no saved graphs\n";
        return false;
    }

}

//to File where all file name stored
void Files::insertFileName(string name) {
    ofstream storedGraphsFile("storedGraphs.txt", ios::app);
    storedGraphsFile << name << endl;
}

//read from Files
Graph Files::readGraphFromFile(int count) {
    //get file name
    ifstream grraphsFile("storedGraphs.txt", ios::out);
    string graphName;
    if (grraphsFile.is_open()) {
        for (int i = 0; i < count; ++i)
            grraphsFile >> graphName;
        cout << "\n\n" << "----------------------------> " << graphName << "\n\n";
    }

    //object of graph class 
    Graph g;
    g.setFileName(graphName);
    g.setFromFile(true);

    //variables to read file's data into
    string iid, source, dest, weight, type;
    try {
        //file
        fstream grraph(filePath + graphName);

        //1st line for id
        grraph >> iid;
        g.setId(stoi(iid));

        //2nd line for the type
        grraph >> type;
        g.setGraphTypeByChar(type[0]);

        if (grraph.is_open()) {
            while (grraph >> source >> dest >> weight) 
            {
                g.addVertex(source);
                if (dest != "-" && weight != "-")
                {
                    g.addVertex(dest);
                    g.graph.at(source).push_back({ dest, stoi(weight) });
                }
            
            }
        }

        return g;
    }
    catch (exception e) {
        cout << "\n\nsomething went wrong: "<< e.what();
    }
}


