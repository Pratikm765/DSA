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

Node* ReverseLLInGroups(Node* node, int k){
    Node *prev = NULL, *curr = node, *next = NULL;

    int i = 0;
    while(curr != NULL && i < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    if(curr!=NULL)
        node->next = ReverseLLInGroups(curr,k);
    return prev;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    PrintList(head);

    head = ReverseLLInGroups(head,3);
    PrintList(head);

    return 0;
}