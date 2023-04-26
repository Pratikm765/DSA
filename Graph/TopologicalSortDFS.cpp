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
    }

    void dfsUtil(int s,vector<bool>& visited, stack<int>& result){
        visited[s] = true;

        for(auto it = adjList[s].begin(); it != adjList[s].end(); it++)
        {
            if(visited[*it] == false)
                dfsUtil(*it,visited,result);            
        }
        result.push(s);
    }

    void topologicalSort(int s){
        vector<bool> visited(vtx,false);
        stack<int> st;

        for(int i = 0; i < vtx; i++){
            if(visited[i] == false)
                dfsUtil(i,visited,st);
        }
        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    } 

};



int main() 
{
    Graph g1(6);

    g1.addEdge(5,2);
    g1.addEdge(5,0);
    g1.addEdge(4,0);
    g1.addEdge(4,1);
    g1.addEdge(2,3);
    g1.addEdge(3,1);

    g1.topologicalSort(0);

    return 0;
}