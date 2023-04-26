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

Node* KthLargestEle(Node* node, int& k){
    if(node == NULL)
        return NULL;

    Node* right = KthLargestEle(node->right,k);
    if(right != NULL)
        return right;
    k--;
    if(k == 0)
        return node;

    return KthLargestEle(node->left,k);
}

int main(){
    Node* root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(60);
    root->left->right = new Node(20);
    root->right->right = new Node(70);
    root->right->left = new Node(50);
    int k = 3;

    Node* rs = KthLargestEle(root,k);
    if(rs != NULL)
        cout << rs->data;
    return 0;
}