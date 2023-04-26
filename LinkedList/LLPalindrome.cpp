#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};

bool LLPalindrome(Node* node){
    stack<int> s1;

    Node* temp = node;
    while(temp != NULL){
        s1.push(temp->data);
        temp = temp->next;
    }

    temp = node;
    while(!s1.empty()){
        if(s1.top() != temp->data)
            return false;
        temp = temp->next;
        s1.pop();
    }
    return true; 
}

int main(){
    Node* first = new Node(7);
    first->next = new Node(6);
    first->next->next = new Node(9);
    first->next->next->next = new Node(5);
    first->next->next->next->next = new Node(7);

    cout << LLPalindrome(first);
    return 0;
}