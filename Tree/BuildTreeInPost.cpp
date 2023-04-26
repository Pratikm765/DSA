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

Node* buildTreeUtil(int post[], int in[], int start, int end, map<int,int>& mp){
    static int postIndex = end;

    if(start > end)
        return NULL;

    Node* node = new Node(post[postIndex--]);

    if(start == end)
        return node;

    int Index = mp[node->data];

    node->right = buildTreeUtil(post,in,Index+1,end,mp);
    node->left = buildTreeUtil(post,in,start,Index-1,mp);

    return node;
}

void LevelOrder(Node* node){
    queue<Node*> qt;
    qt.push(node);

    while(!qt.empty()){
        Node* temp = qt.front();
        qt.pop();
        cout << temp->data << " ";

        if(temp->left)
            qt.push(temp->left);
        if(temp->right)
            qt.push(temp->right);
    }
}

Node* buildTree(int pre[], int in[], int len){
    map<int,int> inMap;

    for(int i = 0; i < len; i++){
        inMap[in[i]] = i;
    }

    return buildTreeUtil(pre,in,0,len-1,inMap);
}


int main(){
    int post[] = {4,5,2,6,7,3,1};
    int in[]  = {4,2,5,1,6,3,7};

    Node *root = buildTree(post, in, 7);
 
    inorder(root); cout << endl;
    LevelOrder(root);
    return 0;
}