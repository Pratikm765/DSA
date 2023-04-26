#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int V;
    Node* next;

    Node(int v){
        V = v;
        next = NULL;
    }
};

class AdjList{
public:
    Node* head;

    AdjList(){
        head = NULL;
    }

    void insertNode(Node* node){
        if(head == NULL)
        {
            head = node;
        }
        else
        {
            Node* curr = head;
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = node;
        }
    }

    void printList(){
        Node* curr = head;
        while(curr){
            cout << curr->V << "-->";
            curr = curr->next;
        }
        cout << "END\n";
    }

};

class Graph{
public:
    int vertices;
    AdjList* AdjacencyLists;

    Graph(int v){
        vertices = v;
        AdjacencyLists = new AdjList[v];
    }

    void addEdge(int s, int d){
        if(AdjacencyLists[s].head == NULL){
            AdjacencyLists[s].insertNode(new Node(s));
            AdjacencyLists[s].insertNode(new Node(d));
        }
        else
        {
            AdjacencyLists[s].insertNode(new Node(d));
        }

        if(AdjacencyLists[d].head == NULL){
            AdjacencyLists[d].insertNode(new Node(d));
            AdjacencyLists[d].insertNode(new Node(s));
        }
        else
        {
            AdjacencyLists[d].insertNode(new Node(s));
        }
    }

    void printAdjList(){
        for(int i = 0; i < vertices; i++){
            AdjacencyLists[i].printList();
        }
    }
};

int main(){
    Graph g1(5);

    g1.addEdge(0, 1);
    g1.addEdge(0, 4);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);

    g1.printAdjList();

    return 0;
}