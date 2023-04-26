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

    void dfsUtil(int s,vector<bool>& visited){
        visited[s] = true;
        cout << s << " ";

        for(auto it = adjList[s].begin(); it != adjList[s].end(); it++)
        {
            if(visited[*it] == false)
                dfsUtil(*it,visited);            
        }
    }

    void dfs(int s){
        vector<bool> visited(vtx,false);

        for(int i = 0; i < vtx; i++){
            if(visited[i] == false)
                dfsUtil(i,visited);
        }
        cout << endl;
    } 

};



int main() 
{
    Graph g1(5);

    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(1,3);
    g1.addEdge(0,4);

    g1.dfs(0);

    return 0;
}