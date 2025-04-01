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

struct CmpEdgePtrs
{
    bool operator()(const Edge* lhs, const Edge* rhs) const
    {
        return lhs->w > rhs->w;
    }
};

int find(vector<int>& parent, int i){
    if(parent[i] == -1)
        return i;

    return find(parent,parent[i]);
}

void Union(vector<int>& parent, vector<int>& rank, int x, int y){
    int p1 = find(parent,x);
    int p2 = find(parent,y);

    if(rank[p1] < rank[p2])
    {
        parent[p1] = p2;
    }
    else if(rank[p1] > rank[p2])
    {
        parent[p2] = p1;
    }
    else
    {
        parent[p2] = p1;
        rank[p1]++;
    }
}

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

    void KruskalMST(){
        priority_queue<Edge*, vector<Edge*>, CmpEdgePtrs> qt;
        
        vector<int> parent(vtxs,-1);
        vector<int> rank(vtxs,0);
        vector<Edge*> result;
        int MinWeight = 0;

        for(int i = 0; i < Edges.size(); i++){
            qt.push(Edges[i]);
        }

        while(!qt.empty()){
            if(result.size() == (vtxs-1))
                break;
            Edge* curr = qt.top();
            qt.pop();

            int u = find(parent,curr->x);
            int v = find(parent,curr->y);
            int w = curr->w;

            if(u != v){
                result.push_back(curr);
                Union(parent,rank,u,v);
                MinWeight += w;
            }

        }

        cout << " min Weight: " << MinWeight << endl;
        for(int i = 0; i < result.size(); i++){
            cout << result[i]->x << " --> " << result[i]->y << " @ " << result[i]->w << endl;
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
    
    g1.KruskalMST();

    return 0;
}