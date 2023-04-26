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

bool isLeaf(Node* node){
    return (node->left == NULL) && (node->right == NULL);
}

void addLeftBoundry(Node* node, vector<int>& res){
    Node* curr = node->left;
    while(curr){
        if(!isLeaf(curr)) 
            res.push_back(curr->data);
        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaves(Node* node, vector<int>& res){
    if(isLeaf(node)){
        res.push_back(node->data);
        return;
    }
    if(node->left)
        addLeaves(node->left,res);

    if(node->right)    
        addLeaves(node->right,res);
}

void addRightBoundry(Node* node, vector<int>& res){
    vector<int> tempres;
    Node* curr = node->right;
    while(curr){
        if(!isLeaf(curr)) 
            tempres.push_back(curr->data);
        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }    

    for(int i = tempres.size()-1; i >= 0; i--){
        res.push_back(tempres[i]);
    }
}

void PrintBoundry(Node* node){
    vector<int> res;

    if (!isLeaf(node)) 
        res.push_back(node -> data);

    addLeftBoundry(node, res);
    addLeaves(node, res);
    addRightBoundry(node, res);

    for(int i : res)
        cout << i << " ";
    cout << endl;
}

int main(){
    Node * root = new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(3);
    root -> left -> left -> right = new Node(4);
    root -> left -> left -> right -> left = new Node(5);
    root -> left -> left -> right -> right = new Node(6);
    root -> right = new Node(7);
    root -> right -> right = new Node(8);
    root -> right -> right -> left = new Node(9);
    root -> right -> right -> left -> left = new Node(10);
    root -> right -> right -> left -> right = new Node(11);

    PrintBoundry(root);
    return 0;
}