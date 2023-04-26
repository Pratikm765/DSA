#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void PrintList(Node* head){
    Node* node = head;
    Node* prevNode = NULL;
    while(node != NULL){
        cout << node->data << "-->";
        prevNode = node;
        node = node->next;
    }
    cout << "NULL\n"; 

    node = prevNode;
    while(node != NULL){
        cout << node->data << "<--";
        node = node->prev;
    }
    cout << "NULL\n"; 
}

Node* ReverseDLL(Node* node){
    Node *curr = node;
    Node* temp = NULL;

    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if(temp != NULL)
        node = temp->prev;
    return node;
}

int main(){
    Node* head = new Node(7);
    
    head->next = new Node(6);
    head->next->prev = head;

    head->next->next = new Node(9);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;

    head->next->next->next->next = new Node(8);
    head->next->next->next->next->prev = head->next->next->next;
    PrintList(head);

    head = ReverseDLL(head);
    PrintList(head);

    return 0;
}