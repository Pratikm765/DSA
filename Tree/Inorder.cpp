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

void inorder(Node* node){
    if(node == NULL)
        return;
    
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void inorderIterative(Node* node){
    Node* curr = node;
    stack<Node*> st;

    while(!st.empty() || curr != NULL){
        // Reach till far left node
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }

        // Print topmost node in stack
        // later traverse right tree wrt curr node
        if(!st.empty()){
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
    cout << endl;
}

void inorderMorrisTraversal(Node* node){
    while(node){
        // reach till far left node
        if(node->left == NULL){
            cout << node->data << " ";
            node = node->right;
        }
        else
        {
            // find inorder predessor of node
            // make pred->next = node
            Node* pred = node->left;
            while(pred->right && pred->right != node)
                pred = pred->right;

            // if already set pred link to node
            // then unlink it, print and move to right
            // otherwise set link and move to left
            if(pred->right == node){
                pred->right = NULL;
                cout << node->data << " ";
                node = node->right;
            }
            else
            { 
                pred->right = node;
                node = node->left;
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

    inorder(head); cout<<endl;
    inorderIterative(head);
    inorderMorrisTraversal(head);
}