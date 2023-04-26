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

void LevelOrder(Node* node){
    queue<Node*> qt;
    qt.push(node);

    while(!qt.empty()){
        Node* temp = qt.front();
        qt.pop();
        cout << temp->data << " ";

        if(temp->left)
            qt.push(temp->left);
        if(temp->right)
            qt.push(temp->right);
    }
}

int main(){
    Node* head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);
    head->right->left = new Node(60);
    head->right->right = new Node(70);

    LevelOrder(head);
}