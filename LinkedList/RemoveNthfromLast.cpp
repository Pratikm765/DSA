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

void RemoveNthNodeFromEnd(Node* node, int n){
    Node* fast = node;
    Node* slow = node;

    for(int i = 0; i < n; i++)
        fast = fast->next;

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
}

int main(){
    Node* first = new Node(7);
    first->next = new Node(6);
    first->next->next = new Node(9);
    first->next->next->next = new Node(5);
    first->next->next->next->next = new Node(8);
    PrintList(first);

    RemoveNthNodeFromEnd(first,2);
    PrintList(first);
    return 0;
}