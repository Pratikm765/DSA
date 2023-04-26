#include<bits/stdc++.h>
using namespace std;

class GraphNode{
public:
    int vtx;
    vector<int> adjList;

    GraphNode(int v){
        vtx = v;
    }

    void addEdge(int d){
        adjList.push_back(d);
    }

    void printAList(){
        for(int i = 0; i < adjList.size(); i++)
            cout << adjList[i] << " ";
        cout << endl;
    }
};

class Graph{
public:
    int vtxs;
    vector<GraphNode*> nodes;

    Graph(int v){
        vtxs = v;
        for(int i = 0; i < v; i++)
        {
            nodes.push_back(new GraphNode(i));
        }
    }

    void addEdge(int s, int d){
        nodes[s]->addEdge(d);
        nodes[d]->addEdge(s);
    }

    void cloneEdge(int s, int d){
        nodes[s]->addEdge(d);
    }

    void printLists(){
        for(int i = 0; i < vtxs; i++){
            cout << nodes[i] << "-->";
            nodes[i]->printAList();
        }
    }
};

Graph cloneGraph(Graph g1)
{
    Graph g2(g1.vtxs);

    for(int i = 0; i < g1.vtxs; i++){
        for(int j = 0; j < g1.nodes[i]->adjList.size(); j++)
            g2.cloneEdge(i,g1.nodes[i]->adjList[j]);
    }

    return g2;
}



int main() 
{
    Graph g1(5);

    g1.addEdge(0,1);
    g1.addEdge(1,2);
    g1.addEdge(2,3);
    g1.addEdge(2,4);
    g1.addEdge(0,4);

    g1.printLists(); cout << endl;

    Graph g2 = cloneGraph(g1);

    g2.printLists();

    return 0;
}