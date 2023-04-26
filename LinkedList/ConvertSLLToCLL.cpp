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
    Node* head = node;
    while(node != NULL){
        cout << node->data << "-->";
        node = node->next;
        if(node == head)
        {
            cout << "Detected Circular Linked list\n";
            return;
        }
    }
    cout << "NULL\n"; 
}

void ConvertSLLToCLL(Node* node){
    Node* head = node;
    while(node->next != NULL){
        node = node->next;
    }
    node->next = head;
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(5);
    head->next->next = new Node(9);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(6);    
    PrintList(head);

    ConvertSLLToCLL(head);
    PrintList(head);
    return 0;
}