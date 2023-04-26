#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    int hd;

    Node(int d){
        data = d;
        left = right = NULL;
        hd = 0;
    }
};

void bottomView(Node* node){
    map<int,int> mt;
    int hd = 0;

    queue<Node*> qt;

    node->hd = hd;
    qt.push(node);

    // keep updating the map with data until we reach leaf nodes
    while(!qt.empty()){
        Node* temp = qt.front();
        hd = temp->hd;
        qt.pop();

        mt[hd] = temp->data;

        if(temp->left != NULL)
        {
            temp->left->hd = hd-1;
            qt.push(temp->left);
        }

        if(temp->right != NULL)
        {
            temp->right->hd = hd+1;
            qt.push(temp->right);
        }
    }

    for(auto i = mt.begin(); i != mt.end(); i++){
        cout << i->second << " ";
    }
}

int main(){
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    cout << "Bottom view of the given binary tree :\n";
    bottomView(root);
    return 0;    
}