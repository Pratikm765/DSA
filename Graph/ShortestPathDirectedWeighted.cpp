#include<bits/stdc++.h>
using namespace std;

class GraphNode{
public:
    int V;
    int W;

    GraphNode(int v, int w)
    {
        V = v;
        W = w;
    }
};

class WGraph{
public:
    int Vtx;
    list<GraphNode*> *adjList;

    WGraph(int v){
        Vtx = v;
        adjList = new list<GraphNode*>[v];
    }

    void addEdge(int s, int d, int w){
        adjList[s].push_back(new GraphNode(d,w));
    }

    void topologicalSortUtil(int s, vector<bool>& visited,stack<int>& st){
        visited[s] = true;

        for(auto it = adjList[s].begin(); it != adjList[s].end(); it++){
            if(visited[(*it)->V] == false)
                topologicalSortUtil((*it)->V,visited,st);
        }
        st.push(s);
    }

    void topologicalSort(stack<int>& st){
        vector<bool> visited(Vtx,false);

        for(int i = 0; i < Vtx; i++)
        {
            if(visited[i] == false)
                topologicalSortUtil(i,visited,st);
        }
    }

    void shortestPath(int s){
        vector<int> dist(Vtx,INT_MAX);

        stack<int> st;
        topologicalSort(st);
        dist[s] = 0;

        while(!st.empty()){
            int curr = st.top();
            st.pop();

            if(dist[curr] != INT_MAX)
            {
                for(auto it = adjList[curr].begin(); it != adjList[curr].end(); it++){
                    if(dist[(*it)->V] > (dist[curr]+ (*it)->W))
                        dist[(*it)->V] = dist[curr] + (*it)->W;
                }
            }
        }

        for(int i = 0; i < Vtx; i++)
        {
            cout << s <<"-->" << i << " : "<< dist[i] << endl;
        }
    }
};

int main(){
        WGraph g4(6);
        g4.addEdge(0, 1, 5);
        g4.addEdge(0, 2, 3);
        g4.addEdge(1, 3, 6);
        g4.addEdge(1, 2, 2);
        g4.addEdge(2, 4, 4);
        g4.addEdge(2, 5, 2);
        g4.addEdge(2, 3, 7);
        g4.addEdge(3, 4, -1);
        g4.addEdge(4, 5, -2);

        cout << "Following are shortest distances from source \n";
        g4.shortestPath(1);
}