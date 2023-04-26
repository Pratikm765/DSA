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

bool isBalanced(Node* root,int* height)
{
    if(root == NULL)
    {
        *height = 0;
        return true;
    }

    int lh,rh;        
    bool lb, rb;

    lb = isBalanced(root->left,&lh);
    rb = isBalanced(root->right,&rh);

    *height = max(lh,rh)+1;

    if(abs(lh-rh) <= 1 )
    {
        return lb && rb;
    }
    else
    {
        return false;
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    //root->left->left->left = new Node(8);

    int height = 0;
    cout << "Balanced Tree: " << isBalanced(root,&height)?"yes":"no";

}