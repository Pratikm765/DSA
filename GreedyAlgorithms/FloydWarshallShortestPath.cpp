#include<bits/stdc++.h>
#define V 4
#define MAX_NUM 99999
using namespace std;

void floydWarshall(int graph[V][V], int s){

    for(int k = 0; k < V; k++)
    {
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    } 
}

int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { { 0, 5, MAX_NUM, 10 },
                        { MAX_NUM, 0, 3, MAX_NUM },
                        { MAX_NUM, MAX_NUM, 0, 1 },
                        { MAX_NUM, MAX_NUM, MAX_NUM, 0 } };

    floydWarshall(graph,0);
    return 0;
}