#include <bits/stdc++.h>
using namespace std;
 
class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

bool PathExists(Node* node, vector<int>& v, int x){
    if(node == NULL)
        return false;
    
    v.push_back(node->data);

    if(node->data == x)
        return true;

    if(PathExists(node->left,v,x) || PathExists(node->right,v,x))
        return true;

    v.pop_back();
    return false;
}

void printPath(Node *root, int x)
{
    vector<int> arr;

    if(PathExists(root,arr,x)){
        for(int i : arr)
            cout << i << " -> ";
        cout << "END";
    }
    else
        cout << "No Path";
}

int main(){
    Node* head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);
    head->right->left = new Node(60);
    head->right->right = new Node(70);

    printPath(head,50);
}


 