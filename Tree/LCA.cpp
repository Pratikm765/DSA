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

Node* LCA(Node* node, int k1, int k2){
    if(node == NULL)
        return NULL;

    if(node->data == k1 || node->data == k2)
        return node;

    Node* lLCA = LCA(node->left,k1,k2);
    Node* rLCA = LCA(node->right,k1,k2);

    if(lLCA && rLCA)
        return node;

    return lLCA !=NULL ? lLCA : rLCA;
}

int main(){
    Node* head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);
    head->right->left = new Node(60);
    head->right->right = new Node(70);

    cout << LCA(head,50,40)->data; 
    return 0;
}