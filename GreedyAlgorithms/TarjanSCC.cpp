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

    void SCCUtil(int s, vector<int>& low, vector<int>& disc, vector<bool>& stackMember, stack<int>& st){
        static int time = 0;

        low[s] = disc[s] = ++time;
        st.push(s);
        stackMember[s] = true;

        for(auto it = adjList[s].begin(); it != adjList[s].end(); it++)
        {
            if(disc[*it] == -1)
            {
                SCCUtil(*it,low,disc,stackMember,st);
                low[s] = min(low[*it],low[s]);
            }
            else if(stackMember[*it] == true)
            {
                low[s] = min(disc[*it],low[s]);
            }
        }

        int w;
        if(low[s] == disc[s]){
            while(st.top() != s){
                w = st.top();
                st.pop();
                stackMember[w] = false;
                cout << w << " ";
            }
            w = st.top();
            st.pop();
            stackMember[w] = false;
            cout << w << "\n";
        }
    }

    void printSCCs(){
        vector<int> low(V,-1);
        vector<int> disc(V,-1);
        vector<bool> stackMember(V,false);
        stack<int> st;

        for(int i = 0; i < V; i++){
            if(disc[i] == -1)
                SCCUtil(i,low,disc,stackMember,st);
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
    g1.printSCCs();

    return 0;
}