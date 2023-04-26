#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
    int x;
    int y;
    int w;

    Edge(int X,int Y,int W){
        x = X;
        y = Y;
        w = W;
    }
};

class Graph{
public:
    int vtxs;
    vector<Edge*> *adjList;
    vector<Edge*> Edges;

    Graph(int V){
        vtxs = V;
        adjList = new vector<Edge*>[vtxs];
    }

    void addEdge(int u, int v, int w){
        adjList[u].push_back(new Edge(u,v,w));
        adjList[v].push_back(new Edge(v,u,w));
        Edges.push_back(new Edge(u,v,w));
    }

    void BellmanFord(int s){
        vector<int> dist(vtxs,INT_MAX);
        dist[s] = 0;

        for(int i = 1; i < vtxs; i++)
        {
            for(int j = 0; j < Edges.size(); j++)
            {
                int u = Edges[j]->x;
                int v = Edges[j]->y;
                int w = Edges[j]->w;

                if((dist[u] != INT_MAX) &&
                   ((dist[u] + w) < dist[v]))
                {
                    dist[v] = dist[u] + w;
                }
            }
        }

        for(int j = 0; j < Edges.size(); j++)
        {
            int u = Edges[j]->x;
            int v = Edges[j]->y;
            int w = Edges[j]->w;

            if((dist[u] != INT_MAX) &&
                ((dist[u] + w) < dist[v]))
            {
                cout << " Negative Cycle " << endl;
                return;
            }
        }

        for(int i = 0; i < vtxs; i++){
            cout << i << " ---> " << dist[i] << endl;
        }
    }
};

int main(){
    
    Graph g1(5);

    g1.addEdge(0, 1, -1);
    g1.addEdge(0, 2, 4);
    g1.addEdge(1, 2, 3);
    g1.addEdge(1, 3, 2);
    g1.addEdge(1, 4, 2);
    g1.addEdge(3, 2, 5);
    g1.addEdge(3, 1, 1);
    g1.addEdge(4, 3, -3);
    
    g1.BellmanFord(0);

    return 0;
}