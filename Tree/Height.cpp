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

int TreeHeight(Node* node){
    if(node == NULL)
        return 0;

    int lh = TreeHeight(node->left);
    int rh = TreeHeight(node->right);

    return max(lh,rh)+1;
}

int main(){
    Node* head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);

    cout << " Height of Tree: " << TreeHeight(head);
}