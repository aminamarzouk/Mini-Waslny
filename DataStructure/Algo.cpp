#include "Algo.h"

Algo::Algo(Graph g) {
    this->g = g;
}
//// Algorithms
void Algo::dijkstra(string source, string destination)
{
    if (g.vertexExist(source) && g.vertexExist(destination))
    {
        string s = source;
        unordered_map<string, int> dist;
        for (auto x : g.graph)
            dist[x.first] = INT_MAX;

        unordered_map<string, bool> visited;
        for (auto x : g.graph)
            visited[x.first] = false;

        //to sotre the path
        unordered_map <string, string> citiesFamily;
        dist[s] = 0;
        citiesFamily[source] = source;
        priority_queue<pair<int, string>> nextToVisit;
        nextToVisit.push({ 0,s });

        while (!nextToVisit.empty())
        {
            string current = nextToVisit.top().second;
            nextToVisit.pop();

            if (visited[current])
                continue;

            visited[current] = true;

            for (auto x : g.graph[current])
            {
                string myDistination = x.first;
                int weight = x.second;
                if (dist[current] + weight < dist[myDistination])
                {
                    dist[myDistination] = dist[current] + weight;
                    nextToVisit.push({ -1 * dist[myDistination],myDistination });
                    citiesFamily[myDistination] = current;
                }
            }
            //break when reach our destination
            if (current == destination)
                break;
        }
        cout << "\nMinimum distance between " << source << " and " << destination << " : " << dist[destination] << "\n";

        //to store path vertices
        string past = citiesFamily[destination];
        stack<string> st;
        st.push(destination);
        while (!st.empty())
        {
            st.push(past);
            if (past == source)
                break;
            past = citiesFamily[past];
        }

        //display the path from source to destination
        int len = st.size();
        cout << "\nThe number of cities which you will path throw them to reach to city (" << destination << ") from (" << source << ") is:\n\n";
        cout << len << " Cities" << "\n\nthe shortest path is :\n";
        for (int i = 0; i < len; ++i) {
            cout << st.top() << endl;
            st.pop();
        }
        cout << "\n";
    }
    else
    {
        cout << "\nDouble check the cities' name ,Please" << '\n';
    }
}


void Algo ::spfa(string source, string destination)
{
    if (g.vertexExist(source) && g.vertexExist(destination))
    {
        string s = source;
        unordered_map<string, int> dist;
        for (auto x : g.graph)
            dist[x.first] = INT_MAX;

        unordered_map<string, bool> visited;
        for (auto x : g.graph)
            visited[x.first] = false;

        //to sotre the path
        unordered_map <string, string> citiesFamily;
        dist[s] = 0;

        queue<string> nextToVisit;
        nextToVisit.push(s);

        while (!nextToVisit.empty())
        {
            string current = nextToVisit.front();
            nextToVisit.pop();

            visited[current] = false;

            for (auto x : g.graph[current])
            {
                string myDistination = x.first;
                int weight = x.second;
                if (dist[current] + weight < dist[myDistination])
                {
                    dist[myDistination] = (dist[current] + weight);
                    if (!visited[myDistination])
                    {
                        visited[myDistination] = true;
                        nextToVisit.push(myDistination);
                    }
                    citiesFamily[myDistination] = current;
                }
            }
        }
        cout << "\nMinimum distance between " << source << " and " << destination << " : " << dist[destination] << "\n";

        //to store path vertices
        string past = citiesFamily[destination];
        stack<string> st;
        st.push(destination);
        while (true)
        {
            st.push(past);
            if (past == source)
                break;
            past = citiesFamily[past];
        }

        //display the path from source to destination
        int len = st.size();
        cout << "\nThe number of cities which you will path throw them to reach to city (" << destination << ") from (" << source << ") is:\n";
        cout << len << " Cities" << "\n\nthe shortest path is :\n";
        for (int i = 0; i < len; ++i) {
            cout << st.top() << endl;
            st.pop();
        }
        cout << '\n';
    }
    else
    {
        cout << "\nDouble check the cities' name ,Please" << '\n';
    }
}


////////////////
