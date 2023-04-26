#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

void FlattenTree(Node* node){
    static Node* prev = NULL;

    if(node == NULL)
        return;

    FlattenTree(node->right);
    FlattenTree(node->left);
    node->right = prev;
    node->left = NULL;
    prev = node;
}

void PrintFlatTree(Node* node){
    while(node){
        cout << node->data << " ";
        node = node->right;
    }
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    FlattenTree(root1);
    PrintFlatTree(root1);
    return 0;
}