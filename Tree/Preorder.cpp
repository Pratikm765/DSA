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

void preorder(Node* node){
    if(node == NULL)
        return;
    
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void preorderIterative(Node* node){
    Node* curr = node;
    stack<Node*> st;

    while(!st.empty() || curr != NULL){
        // keep traversing towards far left
        // also while traversing print it
        // push right nodes to stack for curr
        while(curr != NULL){
            cout << curr->data << " ";
            if(curr->right != NULL)
                st.push(curr->right);
            curr = curr->left;
        }

        // When you done traversing left tree
        // start right tree wrt curr node
        if(!st.empty()){
            curr = st.top();
            st.pop();
        }
    }
    cout << endl;
}

void preorderMorrisTraversal(Node* node){
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
            // then unlink it and move to right
            // otherwise set link, print and move to left
            if(pred->right == node){
                pred->right = NULL;
                node = node->right;
            }
            else
            {
                cout << node->data << " ";
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

    preorder(head); cout<<endl;
    preorderIterative(head);
    preorderMorrisTraversal(head);
}