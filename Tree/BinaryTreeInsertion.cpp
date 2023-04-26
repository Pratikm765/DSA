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

class BinaryTree{
public:
    Node* head;

    BinaryTree(){
        head = NULL;
    }

    void InsertNode(int d){
        if(head == NULL)
        {
            head = new Node(d);
            return;
        }

        queue<Node*> q;

        Node* temp;
        q.push(head);

        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(temp->left != NULL){
                q.push(temp->left);
            }
            else
            {
                temp->left = new Node(d);
                break;
            }

            if(temp->right != NULL){
                q.push(temp->right);
            }
            else
            {
                temp->right = new Node(d);
                break;
            }
        }
    }

    void LevelOrderTraverse(){
        Node* temp;

        queue<Node*> q;
        q.push(head);

        cout << "Level Order Traversal: ";
        while(!q.empty()){
            temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if(temp->left != NULL)
            {
                q.push(temp->left);
            }

            if(temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        cout << endl;
    }  
};



int main(){
    BinaryTree bt;
    bt.InsertNode(10);
    bt.InsertNode(20);
    bt.InsertNode(30);
    bt.InsertNode(40);
    bt.InsertNode(50);

    bt.LevelOrderTraverse();

    return 0;
}