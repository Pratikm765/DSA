#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};

// Do level order traversal
// print first node of every level
void printLeftView(Node* node){
    queue<Node*> q;

    q.push(node);

    while(!q.empty()){
        int qsize = q.size();
        
        for(int i = 0; i < qsize; i++){
            Node* temp = q.front();
            q.pop();
            if(i == 0)
                cout << temp->data << " ";

            if(temp->left)
                q.push(temp->left);
            
            if(temp->right)
                q.push(temp->right);
        }
    }
    cout << endl;
}


int main(){
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right->left = new Node(14);

    printLeftView(root);
    return 0;
}