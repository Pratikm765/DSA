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

    Node* inorderSuccessor(Node* node){
        while(node->left != NULL){
            node = node->left;
        }
        return node;
    }

    Node* deleteNodeUtil(Node* node, int d){
        if(node == NULL)
            return node;

        if(node->data > d)
        {
            node->left = deleteNodeUtil(node->left,d);
        }
        else if(node->data < d)
        {
            node->right = deleteNodeUtil(node->right,d);
        }
        else
        {
            if(node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if(node->left == NULL)
            {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else
            {
                Node* temp = inorderSuccessor(node->right);
                node->data = temp->data;
                node->right = deleteNodeUtil(node->right,temp->data);
                return node;
            }
        }
        return node;
    }

    void deleteNode(int d){
        head = deleteNodeUtil(head,d);
    }
};

int main(){
    BST bst;
    bst.insertNode(40);
    bst.insertNode(20);
    bst.insertNode(60);
    bst.insertNode(30);
    bst.insertNode(50);
    bst.insertNode(10);
    bst.insertNode(70);

    bst.inorder(bst.head); cout << endl;

    bst.deleteNode(60);
    bst.inorder(bst.head); cout << endl;

    return 0;
}