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

void DeleteDeepestNode(Node* head,Node* node){
    queue<Node*> q;
    q.push(head);

    Node* temp;

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp == node){
            temp = NULL;
            delete node;
            return;
        }

        if(temp->right){
            if(temp->right == node){
                temp->right = NULL;
                delete node;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
        if(temp->left){
            if(temp->left == node){
                temp->left = NULL;
                delete node;
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
    }
}

void DeleteNode(Node* head,int key){
    Node* keyNode;

    queue<Node*> q;
    Node* temp;
    q.push(head);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if(temp->data == key){
            keyNode = temp;
        }

        if(temp->left != NULL){
            q.push(temp->left);
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
    swap(temp->data,keyNode->data);
    DeleteDeepestNode(head,temp);
}

void LevelOrderTraverse(Node* head){
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

int main(){
    Node* head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);

    LevelOrderTraverse(head);
    
    DeleteNode(head,10);
    LevelOrderTraverse(head);
    
    return 0;
}