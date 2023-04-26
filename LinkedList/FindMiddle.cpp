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

void FindMiddle(Node* node){
    Node* fast = node;
    Node* slow = node;

    while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast->next != NULL && fast->next->next == NULL)
    {
        cout << "Middle Element: " << slow->data << " and " << slow->next->data << endl;
    }
    else
    {
        cout << "Middle Element: " << slow->data << endl;
    }
}

int main(){
    Node* first = new Node(7);
    first->next = new Node(5);
    first->next->next = new Node(9);
    first->next->next->next = new Node(4);
    first->next->next->next->next = new Node(3);

    FindMiddle(first);
    return 0;
}