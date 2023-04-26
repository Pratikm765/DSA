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

void postorder(Node* node){
    if(node == NULL)
        return;
    
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}

void postorderIterative(Node* node){
    Node* curr = node;
    stack<Node*> st;

    while(!st.empty() || curr != NULL){
        // Reach till far left node
        // insert curr and curr->right to stack
        while(curr != NULL){
            if(curr->right != NULL)
                st.push(curr->right);
            st.push(curr);
            curr = curr->left;
        }

        if(!st.empty()){
            curr = st.top();
            st.pop();
            // check if right subtree is processed or not
            // if not then processed right subtree first 
            // later go back to curr node
            if(curr->right != NULL && !st.empty() && curr->right == st.top()){
                st.pop();
                st.push(curr);
                curr = curr->right;
            }
            else
            {
                cout << curr->data << " ";
                curr = NULL;
            }
        }
    }
    cout << endl;
}

int main(){
    Node* head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);
    head->right->left = new Node(60);
    head->right->right = new Node(70);

    postorder(head); cout<<endl;
    postorderIterative(head);
}