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

int diameter(Node* node,int* height){
    if(node == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ld = 0, rd = 0;

    ld = diameter(node->left,&lh);
    rd = diameter(node->right,&rh);

    *height = max(lh,rh)+1;

    return max(lh+rh+1,max(ld,rd));
}

int findDiameter(Node* node){
    int height = 0;
    return diameter(node,&height);
}

int main(){
    Node* head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);
    head->right->left = new Node(60);
    head->right->right = new Node(70);

    cout << findDiameter(head);
    return 0;
}