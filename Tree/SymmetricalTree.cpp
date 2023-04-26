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

bool SymmetricalTree(Node* root1,Node* root2)
{
    if(root1 == NULL || root2 == NULL)
        return root1 == root2;
    
    return ((root1->data == root2->data) &&
            (SymmetricalTree(root1->left,root2->right)) &&
            (SymmetricalTree(root1->right,root2->left)));
}

// Mirror Tree
bool IsSymmetricalTree(Node* node){
    if(!node)
        return false;

    return SymmetricalTree(node->left,node->right);
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    root1->right->left = new Node(4);
    root1->right->right = new Node(3);

    cout << IsSymmetricalTree(root1);
    return 0;
}