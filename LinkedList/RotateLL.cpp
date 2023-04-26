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

Node* RotateLL(Node* head, int k){
    Node* temp = head;

    int count = 1;
    while(temp->next != NULL && count < k){
        temp = temp->next;
        count++;
    }
    
    Node* node = temp;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head = node->next;
    node->next = NULL;

    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    PrintList(head);

    head = RotateLL(head,4);
    PrintList(head);

    return 0;
}