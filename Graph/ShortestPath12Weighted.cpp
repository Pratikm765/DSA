#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int V;
    list<int>* adjList;

    Graph(int v){
        V = v;
        adjList = new list<int> [2*v];
    }

    void addEdge(int s, int d, int w){
        if(w == 1)
        {
            adjList[s].push_back(d);
        }
        else if(w == 2)
        {
            adjList[s].push_back(s+V);
            adjList[s+V].push_back(d);
        }
    }

    int PrintShortestPath(int s, int d, vector<int>& parent){
        static int Level = 0;
        if(parent[s] == -1)
        {
            cout << "Path between " << s << " And " << d <<" : " << s << " ";
            return Level;
        }

        PrintShortestPath(parent[s],d,parent);

        Level++;

        if(s < V)
            cout << s << " ";

        return Level;
    }

    int shortestDistance(int s, int d){
        queue<int> qt;
        vector<bool> visited(2*V,false);
        vector<int> parent(2*V,-1);

        qt.push(s);
        visited[s] = true;

        while(!qt.empty()){
            int curr = qt.front();
            qt.pop();

            if(curr == d)
            {
                return PrintShortestPath(curr,d,parent);
            }

            for(auto it = adjList[curr].begin(); it != adjList[curr].end(); it++){
                if(visited[*it] == false){
                    visited[*it] = true;
                    qt.push(*it);
                    parent[*it] = curr;
                }
            }
        }
        return 0;
    }

};


int main()
{
    int V = 4;
    Graph g(V);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 0, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(3, 3, 2);
 
    int src = 0, dest = 3;
    int level = g.shortestDistance(src, dest);
    cout << "\nShortest Distance between " << src
        << " and " << dest << " is "
        << level;
 
    return 0;
}