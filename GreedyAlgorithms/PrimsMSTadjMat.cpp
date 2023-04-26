#include<bits/stdc++.h>
#define V 5
using namespace std;

int getMinKey(vector<int>& MSTKey, vector<bool>& visited){
    int MinKey = INT_MAX;
    int MinIndex = V;

    for(int i = 0; i < V; i++){
        if(visited[i] == false && MSTKey[i] < MinKey)
        {
            MinKey = MSTKey[i];
            MinIndex = i;
        }
    }
    return MinIndex;
}

void PrintMST(vector<int>& parent, vector<int>& MSTKey){
    cout << "Edge \tWeight\n";
    for(int i = 1; i < V; i++){
        cout << parent[i] << " --> " << i << " @ " << MSTKey[i] << endl;
    }
}

void primMST(int graph[V][V]){

    vector<int> parent(V,-1);
    vector<bool> visited(V,false);
    vector<int> MSTKey(V,INT_MAX);

    MSTKey[0] = 0;

    for(int i = 0; i < V-1; i++){
        int u = getMinKey(MSTKey,visited);

        visited[u] = true;

        for(int j = 0; j < V; j++){
            if((graph[u][j] != 0) &&
               (visited[j] == false) &&
               (graph[u][j] < MSTKey[j]))
            {
                parent[j] = u;
                MSTKey[j] = graph[u][j];
            }
        }
    }

    PrintMST(parent,MSTKey);
}

int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    primMST(graph);
    return 0;
}