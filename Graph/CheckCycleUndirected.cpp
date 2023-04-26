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

    bool dfsUtil(int s,int parent, vector<bool>& visited){
        visited[s] = true;

        for(auto it = adjList[s].begin(); it != adjList[s].end(); it++)
        {
            if(visited[*it] == false)
            {
                if(dfsUtil(*it,s,visited))
                    return true;
            }
            else if(parent != *it)     
                return true;       
        }
        return false;
    }

    bool  checkCycle(){
        vector<bool> visited(vtx,false);

        for(int i = 0; i < vtx; i++){
            if(visited[i] == false)
            {
                if(dfsUtil(i,-1,visited))
                    return true;
            }     
        }
        return false;
    } 

};



int main() 
{
    Graph g1(5);

    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    //g1.addEdge(1,4);

    cout << g1.checkCycle();

    return 0;
}