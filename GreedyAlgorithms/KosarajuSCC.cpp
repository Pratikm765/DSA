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
    }

    void DFSUtil(int s, vector<bool>& visited){
        visited[s] = true;
        cout << s << " ";
        for(auto it = adjList[s].begin(); it != adjList[s].end(); it++)
        {
            if(visited[*it] == false)
            {
                DFSUtil(*it,visited);
            }
        }
    }

    void topologicalSort(int s, vector<bool>& visited, stack<int>& st){
        visited[s] = true;

        for(auto it = adjList[s].begin(); it != adjList[s].end(); it++)
        {
            if(visited[*it] == false)
            {
                topologicalSort(*it,visited,st);
            }
        }
        st.push(s);
    }

    void TransposeGraph(Graph* g2){

        for(int i = 0; i < V; i++){
            for(auto it = adjList[i].begin(); it != adjList[i].end(); it++)
            {
                g2->adjList[*it].push_back(i);
            }
        }
    }

    void printSCCs(){
        int s;
        vector<bool> visited(V,false);
        stack<int> st;
        
        for(int i = 0; i < V; i++){
            if(visited[i] == false)
                topologicalSort(s,visited,st);
        }

        for(int i = 0; i < V; i++){
            visited[i] = false;
        }

        Graph g2(V);
        TransposeGraph(&g2);

        while(!st.empty()){
            s = st.top();
            st.pop();

            if(visited[s] == false)
            {
                g2.DFSUtil(s,visited);
                cout << endl;
            }
        }
    }
};


int main(){
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
 
    cout << "Following are strongly connected components in "
            "given graph \n";
    g.printSCCs();
}