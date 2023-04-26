#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};

void buildDLL(Node* node, Node** head, Node** tail){
    if(node == NULL)
        return;

    buildDLL(node->left,head,tail);
    
    if(*head == NULL)
        *head = node;
    
    node->left = *tail;

    if(*tail != NULL)
        (*tail)->right = node;

    *tail = node;

    buildDLL(node->right,head,tail);
}

int main(){
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(60);
    root->left->right = new Node(20);
    root->right->right = new Node(70);
    root->right->left = new Node(50);

    Node* head = NULL;
    Node* tail = NULL;
    buildDLL(root,&head,&tail);
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
    return 0;
}