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

void storeBSTNodes(Node* node, vector<Node*>& BSTNodes)
{
    if(node == NULL)
        return;
    storeBSTNodes(node->left,BSTNodes);
    BSTNodes.push_back(node);
    storeBSTNodes(node->right,BSTNodes);
}

Node* buildTreeUtil(vector<Node*>& BSTNodes, int start, int end)
{
    if(start > end)
        return NULL;

    int mid = (start+end)/2;

    BSTNodes[mid]->left = buildTreeUtil(BSTNodes,start,mid-1);
    BSTNodes[mid]->right = buildTreeUtil(BSTNodes,mid+1,end);

    return BSTNodes[mid];   
}


Node* buildTree(Node* node){
    vector<Node*> BSTNodes;
    storeBSTNodes(node,BSTNodes);
    return buildTreeUtil(BSTNodes,0,BSTNodes.size()-1);
}

void preOrder(Node* node){
    if(node == NULL)
        return;

    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
 
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);

    preOrder(root); cout << endl;
 
    root = buildTree(root);
 
    cout << "Preorder traversal of balanced BST is : ";
    preOrder(root);
 
    return 0;
}