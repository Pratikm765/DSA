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

int findMaxPathSum(Node* node, int& maxim){
    if(node == NULL)
        return 0;

    int leftMaxPath = max(0,findMaxPathSum(node->left,maxim));
    int rightMaxPath = max(0,findMaxPathSum(node->right,maxim));

    int d = node->data;
    maxim = max(maxim,d+leftMaxPath+rightMaxPath);
    return max(leftMaxPath,rightMaxPath) + d;
}

int MaxPathSum(Node* node){
    int maxim = INT_MIN;
    findMaxPathSum(node,maxim);
    return maxim;
}

int main(){
    Node * root = new Node(-10);
    root -> left = new Node(9);
    root -> right = new Node(20);
    root -> right -> left = new Node(15);
    root -> right -> right = new Node(7);

    cout << MaxPathSum(root);
}