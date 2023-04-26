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
        //adjList[d].push_back(s);
    }

    bool dfsUtil(int s, vector<bool>& visited, vector<bool>& recurPath){
        
        if(visited[s] == false){
            visited[s] = true;
            recurPath[s] = true;

            for(auto it = adjList[s].begin(); it != adjList[s].end(); it++)
            {
                if(visited[*it] == false)
                {
                    if(dfsUtil(*it,visited,recurPath))
                        return true;
                }
                else if(recurPath[*it])     
                    return true;       
            }
        }
        recurPath[s] = false;
        return false;
    }

    bool  checkCycle(){
        vector<bool> visited(vtx,false);
        vector<bool> recurPath(vtx,false);

        for(int i = 0; i < vtx; i++){
            if(visited[i] == false)
            {
                if(dfsUtil(i,visited,recurPath))
                    return true;
            }     
        }
        return false;
    } 

    // for cycle consists of all vertices count of vertex traversed is 0
    // for graph with cycle which excludes n vertices, count will be n.
    bool checkCycleKahn(){
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
            count++;

            for(auto it = adjList[curr].begin(); it != adjList[curr].end(); it++)
            {
                indegree[*it]--;
                if(indegree[*it] == 0)
                    qt.push(*it);
            }            
        }

        if(count == vtx)
            return false;

        return true;        
    }

};



int main() 
{
    Graph g1(5);

    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    //g1.addEdge(4,1);

    cout << g1.checkCycle() << endl;
    cout << g1.checkCycleKahn() << endl;

    return 0;
}