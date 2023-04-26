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

    void topologicalSortKahn(){
        vector<int> indegree(vtx,0);
        queue<int> qt;

        for(int i = 0; i < vtx; i++){
            for(auto it = adjList[i].begin(); it != adjList[i].end(); it++)
            {
                indegree[*it]++;
            }
        }

        for(int i = 0; i < vtx; i++){
            if( indegree[i] == 0)
                qt.push(i);
            
        }        

        int count = 0;
        while(!qt.empty()){
            int curr = qt.front();
            qt.pop();
            cout << curr << " ";

            for(auto it = adjList[curr].begin(); it != adjList[curr].end(); it++)
            {
                indegree[*it]--;
                if(indegree[*it] == 0)
                    qt.push(*it);
            }            
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

    g1.topologicalSortKahn();

    return 0;
}