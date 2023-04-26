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

void topView(Node* node){
    // ... root-2 root-1 root root+1 root+2 ...
    // for left part using stack as we go backwards
    stack<Node*> lt;
    vector<Node*> rt;

    queue<pair<Node*,int>> qt;

    qt.push(make_pair(node,0));

    int ld = 0 , rd = 0;
    int hd = 0;

    while(!qt.empty()){
        Node* temp = qt.front().first;
        hd = qt.front().second;
        qt.pop();

        // check if we have got nodes with distance
        // less than ld
        // more than rd
        // put left part of topview in stack
        if(hd < ld)
        {
            lt.push(temp);
            ld = hd;
        }
        // put right part of topview in vector
        else if(hd > rd)
        {
            rt.push_back(temp);
            rd = hd;
        }

        // we start from root with d = 0
        // goes to left by decreasing d by 1
        // goes to right by increasing d by 1
        if(temp->left)
            qt.push(make_pair(temp->left,hd-1));
        
        if(temp->right)
            qt.push(make_pair(temp->right,hd+1));
    }

    while(!lt.empty())
    {
        cout << lt.top()->data << " ";
        lt.pop();
    }

    cout << node->data << " ";

    for(auto x : rt){
        cout << x->data << " ";
    }
    cout << endl;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    cout<<"Following are nodes in top view of Binary Tree"<<endl;
    topView(root);
    return 0;    
}