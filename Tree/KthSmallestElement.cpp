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

Node* KthSmallestEle(Node* node, int& k){
    if(node == NULL)
        return NULL;

    Node* left = KthSmallestEle(node->left,k);
    if(left != NULL)
        return left;
    k--;
    if(k == 0)
        return node;

    return KthSmallestEle(node->right,k);
}

int main(){
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(60);
    root->left->right = new Node(20);
    root->right->right = new Node(70);
    int k = 3;

    Node* rs = KthSmallestEle(root,k);
    if(rs != NULL)
        cout << rs->data;
    return 0;
}