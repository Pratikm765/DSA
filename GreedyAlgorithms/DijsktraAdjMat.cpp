#include<bits/stdc++.h>
#define V 9
using namespace std;

int getMinDist(vector<int>& dist, vector<bool>& visited){
    int MinIndex; 
    int MinDist = INT_MAX;

    for(int i = 0; i < V; i++){
        if(visited[i] == false && dist[i] < MinDist)
        {
            MinIndex = i;
            MinDist = dist[i];
        }
    }
    return MinIndex;
}

void dijkstra(int graph[V][V], int s){
    vector<bool> visited(V,false);
    vector<int> dist(V,INT_MAX);

    dist[s] = 0;

    for(int i = 0; i < V-1; i++){
        s = getMinDist(dist,visited);
        visited[s] = true;

        for(int j = 0; j < V; j++){
            if((graph[s][j] != 0) &&
               (visited[j] == false) &&
               (dist[s] != INT_MAX) &&
               ((dist[s]+graph[s][j]) < dist[j]))
            {
                dist[j] = dist[s] + graph[s][j];
            }
        }
    }

    for(int i = 0; i < V; i++){
        cout << i << " ---> " << dist[i] << endl;
    }
}


int main(){
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
}