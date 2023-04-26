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

Node* ExchFirstLastCLL(Node* node){
    Node* head = node;
    if(node->next == head){
        return head;
    }
    while(node->next->next != head){
        node = node->next;
    }
    
    Node* temp = node->next;
    node->next = head;
    temp->next = head->next;
    head->next = temp;
    head = temp;
    return head;
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(5);
    head->next->next = new Node(9);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = head;    
    PrintList(head);

    PrintList(ExchFirstLastCLL(head));
    return 0;
}