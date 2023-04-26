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

bool isSumProperty(Node* node){
    if((node == NULL) ||
       (node->left == NULL && node->right == NULL))
        return true;

    int ld = 0, rd = 0;

    if(node->left != NULL)
        ld = node->left->data;

    if(node->right != NULL)
        rd = node->right->data;

    if((node->data == (ld+rd)) &&
       (isSumProperty(node->left)) &&
       (isSumProperty(node->right)))
       return true;

    return false;
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);
 
    if (isSumProperty(root))
        cout << "Satisfied ";
    else
        cout << "Not Satisfied";

    return 0;
}