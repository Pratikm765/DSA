#include<bits/stdc++.h>
using namespace std;

class Graph{
public:
    int vtx;
    list<int>* adjList;

    Graph(int v){
        vtx = v;
        adjList = new list<int>[v];
    }

    void addEdge(int s, int d){
        adjList[s].push_back(d);
        adjList[d].push_back(s);
    }

    void bfs(int s){
        queue<int> qt;
        vector<bool> visited(vtx,false);

        qt.push(s);
        visited[s] = true;

        while(!qt.empty()){
            int curr = qt.front();
            qt.pop();
            cout << curr << " ";

            for(auto it = adjList[curr].begin(); it != adjList[curr].end(); it++)
            {
                if(visited[*it] == false)
                {
                    qt.push(*it);
                    visited[*it] = true;
                }
                
            }
        }
    }

};



int main() 
{
    Graph g1(5);

    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(0,4);

    g1.bfs(0);

    return 0;
}