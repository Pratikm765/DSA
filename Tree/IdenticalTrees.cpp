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

bool IdenticalTrees(Node* root1,Node* root2)
{
    if(root1 == NULL || root2 == NULL)
        return root1 == root2;
    
    return ((root1->data == root2->data) &&
            (IdenticalTrees(root1->left,root2->left)) &&
            (IdenticalTrees(root1->right,root2->right)));
}

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    //root2->left->right = new Node(5);

    cout << IdenticalTrees(root1,root2);

}