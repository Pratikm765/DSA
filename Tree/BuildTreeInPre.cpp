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

Node* buildTreeUtil(int pre[], int in[], int start, int end, map<int,int>& mp){
    static int preIndex = 0;

    if(start > end)
        return NULL;

    Node* node = new Node(pre[preIndex++]);

    if(start == end)
        return node;

    int Index = mp[node->data];

    node->left = buildTreeUtil(pre,in,start,Index-1,mp);
    node->right = buildTreeUtil(pre,in,Index+1,end,mp);

    return node;
}


Node* buildTree(int pre[], int in[], int len){
    map<int,int> inMap;

    for(int i = 0; i < len; i++){
        inMap[in[i]] = i;
    }

    return buildTreeUtil(pre,in,0,len-1,inMap);
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


int main(){
    int pre[] = {1,2,4,5,3,6,7};
    int in[]  = {4,2,5,1,6,3,7};

    Node *root = buildTree(pre, in, 7);
 
    inorder(root); cout << endl;
    LevelOrder(root);
    return 0;
}