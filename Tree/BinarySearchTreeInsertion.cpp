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

class BST{
public:
    Node* head;
    BST(){
        head = NULL;
    }

    Node* insertNodeUtil(Node* node, int d){
        if(node == NULL)
            return new Node(d);

        if(node->data > d)
            node->left = insertNodeUtil(node->left,d);
        else if(node->data < d)
            node->right = insertNodeUtil(node->right,d);
        
        return node;
    }

    void insertNode(int d){
        head = insertNodeUtil(head,d);
    }

    void inorder(Node* node){
        if(node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main(){
    BST bst;
    bst.insertNode(40);
    bst.insertNode(20);
    bst.insertNode(60);
    bst.insertNode(30);
    bst.insertNode(50);

    bst.inorder(bst.head);
    return 0;
}