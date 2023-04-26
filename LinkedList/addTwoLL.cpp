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

void PrintList(Node* node){
    while(node != NULL){
        cout << node->data << "-->";
        node = node->next;
    }
    cout << "NULL\n"; 
}

Node* addLL(Node* first, Node* second){
    Node* result = NULL;

    stack<int> s1, s2, s3;

    while(first != NULL){
        s1.push(first->data);
        first = first->next;
    }

    while(second != NULL){
        s2.push(second->data);
        second = second->next;
    }

    int carry = 0;
    while(!s1.empty() && !s2.empty()){
        int t1 = s1.top();
        int t2 = s2.top();

        int t3 = carry + t1 + t2;
        s3.push(t3%10);
        
        carry = t3/10;

        s1.pop();
        s2.pop();
    }

    while(!s1.empty()){
        int t1 = s1.top();

        int t2 = carry + t1;
        s3.push(t2%10);
        carry = t2/10;

        s1.pop();
    }

    while(!s2.empty()){
        int t1 = s2.top();

        int t2 = carry + t1;
        s3.push(t2%10);
        carry = t2/10;

        s2.pop();
    }

    Node* curr = NULL;
    while(!s3.empty()){
        if(result == NULL){
            result = new Node(s3.top());
            curr = result;
        }
        else
        {
            curr->next = new Node(s3.top());
            curr = curr->next;
        }
        s3.pop();
    }
    return result;
}

int main(){
    Node* first = new Node(7);
    first->next = new Node(5);
    first->next->next = new Node(9);
    first->next->next->next = new Node(4);
    first->next->next->next->next = new Node(6);

    Node* second = new Node(8);
    second->next = new Node(4);

    Node* result = addLL(first,second);

    PrintList(first);
    PrintList(second);
    PrintList(result);

    return 0;
}