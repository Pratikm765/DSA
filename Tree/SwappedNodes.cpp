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

void CorrectBSTUtil(Node* node,Node** first,Node** middle,Node** last, Node** prev)
{
    if(node == NULL)
        return;

    CorrectBSTUtil(node->left,first,middle,last,prev);

    if(*prev != NULL && (*prev)->data > node->data){
        if(*first == NULL){
            *first = *prev;
            *middle = node;
        }
        else
        {
            *last = node;
        }
    }
    *prev = node;

    CorrectBSTUtil(node->right,first,middle,last,prev);
}

void CorrectBST(Node* node){
    Node *first = NULL, *middle = NULL;
    Node *last = NULL, *prev = NULL;

    CorrectBSTUtil(node,&first,&middle,&last,&prev);

    if(first && last)
        swap(first->data,last->data);
    else if(first && middle)
        swap(first->data,middle->data);
}

void inorder(Node* node)
{
    if(node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

int main(){
    Node *root = new Node(6);
    root->left = new Node(10);
    root->right = new Node(2);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    inorder(root); cout << endl;
 
    CorrectBST(root);

    inorder(root); cout << endl;
    return 0;
}