#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    int height;
    Node(int d){
        data = d;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree{
public: 
    Node* root;
    AVLTree(){
        root = NULL;
    }

    int getHeight(Node* node)
    {
        if(node == NULL)
            return 0;

        return node->height;
    }
    
    int getBalance(Node* node)
    {
        if(node == NULL)
            return 0;

        return getHeight(node->left) - getHeight(node->right);
    }


    //          z                                      y 
    //         / \                                   /   \
    //        y   T4      Right Rotate (z)          x      z
    //       / \          - - - - - - - - ->      /  \    /  \ 
    //      x   T3                               T1  T2  T3  T4
    //     / \
    //   T1   T2
    Node* RotateRight(Node* node){
        Node* leftNode = node->left; // y
        Node* leftChild = leftNode->right; // T3

        leftNode->right = node; // z
        node->left = leftChild; // T3

        node->height = max(getHeight(node->left),getHeight(node->right))+1;
        leftNode->height = max(getHeight(leftNode->left),getHeight(leftNode->right))+1;

        return leftNode;
    }

    //   z                                y
    //  /  \                            /   \ 
    // T1   y     Left Rotate(z)       z      x
    //     /  \   - - - - - - - ->    / \    / \
    //    T2   x                     T1  T2 T3  T4
    //        / \
    //       T3  T4
    Node* RotateLeft(Node* node){
        Node* rightNode = node->right; // y
        Node* rightChild = rightNode->left; // T2

        rightNode->left = node; // z
        node->right = rightChild; // T2

        node->height = max(getHeight(node->left),getHeight(node->right))+1;
        rightNode->height = max(getHeight(rightNode->left),getHeight(rightNode->right))+1;

        return rightNode;
    }

    Node* insertNodeUtil(Node* node, int d){
        if(node == NULL)
            return new Node(d);

        if(d < node->data)
            node->left = insertNodeUtil(node->left,d);
        else if(d > node->data)
            node->right = insertNodeUtil(node->right,d);
        else 
            return node;

        
        node->height = 1 + max(getHeight(node->left),getHeight(node->right));
        
        int bal = getBalance(node);

        // LL Case
        if(bal > 1 && d < node->left->data)
        {
            // cout << "Hit LL case\n";
            return RotateRight(node);
        }
        // RR Case
        else if(bal < -1 && d > node->right->data)
        {
            // cout << bal << " Hit RR case " << node->data << endl;
            return RotateLeft(node);
        }
        // LR Case
        else if(bal > 1 && d > node->left->data)
        {
            // cout << "Hit LR case\n";
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }
        // RL Case
        else if(bal < -1 && d < node->right->data)
        {
            // cout << "Hit RL case\n";
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }
        return node;
    }

    void insertNode(int d){
        root = insertNodeUtil(root,d);
    }   
};

void preOrder(Node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    AVLTree avltree;
    avltree.insertNode(10);
    avltree.insertNode(20); preOrder(avltree.root); cout << endl;
    avltree.insertNode(30); preOrder(avltree.root); cout << endl;
    avltree.insertNode(40); preOrder(avltree.root); cout << endl;
    avltree.insertNode(50); preOrder(avltree.root); cout << endl;
    avltree.insertNode(25);

    preOrder(avltree.root);

}