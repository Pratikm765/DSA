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

bool isBSTUtil(Node* node, int min, int max){
    if(node == NULL)
        return true;

    if((node->data < min) || (node->data > max))
        return false;

    return (isBSTUtil(node->left,min,node->data-1) &&
       isBSTUtil(node->right,node->data+1,max));
}

bool isBST(Node* node)
{
    return (isBSTUtil(node, INT_MIN, INT_MAX));
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);

    cout << "Is BST: " << isBST(root);
 
    return 0;
}