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

// priority_queue treats Compare as a “should this go lower in priority?” function.
// if function returns true then lhs has less priority than rhs
struct CmpEdgePtrs
{
    bool operator()(const Edge* lhs, const Edge* rhs) const
    {
        return lhs->w > rhs->w;
    }
};

class Graph{
public:
    int vtxs;
    vector<Edge*> *adjList;
    int Edges;

    Graph(int V){
        vtxs = V;
        adjList = new vector<Edge*>[vtxs];
        Edges = 0;
    }

    void addEdge(int u, int v, int w){
        adjList[u].push_back(new Edge(u,v,w));
        adjList[v].push_back(new Edge(v,u,w));
        Edges++;
    }

    void Dijsktra(int s){
        priority_queue<Edge*, vector<Edge*>, CmpEdgePtrs> qt;
        vector<int> dist(vtxs,INT_MAX);

        qt.push(new Edge(0,-1,0));
        dist[s] = 0;

        while(!qt.empty()){
            Edge* curr = qt.top();
            qt.pop();

            for(auto it = adjList[curr->x].begin(); it != adjList[curr->x].end(); it++){
                s = curr->x;
                int d = (*it)->y;
                int w = (*it)->w;
                if((dist[s] + w) < dist[d])
                {
                    dist[d] = dist[s] + w;
                    qt.push(new Edge(d,s,w));
                }
            }
        }

        for(int i = 0; i < vtxs; i++){
            cout << i << " ---> " << dist[i] << endl;
        }
    }
};

int main(){
    
    Graph g1(9);

    g1.addEdge(0, 1, 4);
    g1.addEdge(0, 7, 8);
    g1.addEdge(1, 2, 8);
    g1.addEdge(1, 7, 11);
    g1.addEdge(2, 3, 7);
    g1.addEdge(2, 8, 2);
    g1.addEdge(2, 5, 4);
    g1.addEdge(3, 4, 9);
    g1.addEdge(3, 5, 14);
    g1.addEdge(4, 5, 10);
    g1.addEdge(5, 6, 2);
    g1.addEdge(6, 7, 1);
    g1.addEdge(6, 8, 6);
    g1.addEdge(7, 8, 7);
    
    g1.Dijsktra(0);

    return 0;
}