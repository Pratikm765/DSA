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

// Using Level order traversal 
// find level with maximum nodes
// that will be maximum width of tree
int findWidth(Node* node){
    int maxWidth = INT_MIN;

    queue<Node*> qt;

    qt.push(node);

    while(!qt.empty()){
        int qSize = qt.size();
        maxWidth = max(maxWidth,qSize);
        for(int i = 0; i < qSize; i++){
            Node* temp = qt.front();
            qt.pop();

            if(temp->left)
                qt.push(temp->left);
            if(temp->right)
                qt.push(temp->right);
        }
    }
    return maxWidth;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(7);    

    cout << "Maximum width: " << findWidth(root);
    return 0;
}