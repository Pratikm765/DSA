#include<bits/stdc++.h>
using namespace std;



class Graph{
public:
    int V;
    list<int> *adjList;

    Graph(int v){
        V = v;
        adjList = new list<int> [v];
    }

    void addEdge(int s, int d){
        adjList[s].push_back(d);
        adjList[d].push_back(s);
    }

    void TarjanAPUtil(int s, int time, vector<int>& low, vector<int>& disc, vector<bool>& visited, vector<bool>& AP, int parent){
        int children = 0;

        low[s] = disc[s] = ++time;
        visited[s] = true;

        for(auto it = adjList[s].begin(); it != adjList[s].end(); it++)
        {
            if(visited[*it] == false)
            {
                children++;
                TarjanAPUtil(*it,time,low,disc,visited,AP,s);
                low[s] = min(low[*it],low[s]);

                if(parent != -1 && disc[s] <= low[*it])
                    AP[s] = true;
            }
            else if(parent != *it)
            {
                low[s] = min(disc[*it],low[s]);
            }
        }

        if(parent == -1 && children > 1)
            AP[s] = true;
    }

    void TarjanAP(){
        vector<int> low(V,-1);
        vector<int> disc(V,-1);
        vector<bool> AP(V,false);
        vector<bool> visited(V,false);
        int parent = -1;
        int time = 0;

        for(int i = 0; i < V; i++){
            if(visited[i] == false)
                TarjanAPUtil(i,time,low,disc,visited,AP,parent);
        }

        for(int i = 0; i < V; i++){
            if(AP[i] == true)
                cout << i << " ";
        }
    }

};


int main(){
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.TarjanAP();

    return 0;
}