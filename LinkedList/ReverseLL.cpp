#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

void PrintList(Node* node){
    while(node != NULL){
        cout << node->data << "-->";
        node = node->next;
    }
    cout << "NULL\n"; 
}

Node* ReverseLL(Node* node){
    Node *prev = NULL, *curr = node, *next = NULL;

    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(6);
    head->next->next = new Node(9);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(8);
    PrintList(head);

    head = ReverseLL(head);
    PrintList(head);

    return 0;
}