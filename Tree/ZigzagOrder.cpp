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

void ZigzagOrder(Node* node){
    queue<Node*> qt;
    qt.push(node);
    bool flag = true; // flag = false for Spiral
    stack<int> st;

    while(!qt.empty()){
        int qSize = qt.size();
        for(int i = 0; i < qSize; i++)
        {
            Node* temp = qt.front();
            qt.pop();
            
            if(flag)
                cout << temp->data << " ";
            else
                st.push(temp->data);

            if(temp->left)
                qt.push(temp->left);
            if(temp->right)
                qt.push(temp->right);
        }
        flag = !flag;
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }

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

    ZigzagOrder(head);
}