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

Node* getTail(Node* head){
    while(head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

Node* partitionLL(Node* start, Node* end, Node** newStart, Node** newEnd){
    Node* pivot = end;
    Node* curr = start;
    Node* prev = NULL;
    Node* tail = end;
    while(curr != pivot){
        if(curr->data < pivot->data){
            if(*newStart == NULL)
                *newStart = curr;
            prev = curr;
            curr = curr->next;
        }
        else{
            if(prev != NULL)
                prev->next = curr->next;
            Node* temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }
    if(*newStart == NULL)
        *newStart = pivot;

    *newEnd = tail;

    return pivot;
}

Node* QsortLL(Node* start, Node* end){
	if(!start || start==end)
		return start;

    Node* newStart = NULL;
    Node* newEnd = NULL;
    Node* pivot = partitionLL(start,end,&newStart,&newEnd);

    if(newStart != pivot){
        Node* curr = newStart;
        while(curr->next != pivot){
            curr = curr->next;
        }
        curr->next = NULL;

        newStart = QsortLL(newStart,curr);
        getTail(newStart)->next = pivot;
    }
    pivot->next = QsortLL(pivot->next,newEnd);

    return newStart;
}

int main(){
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    PrintList(head);

    head = QsortLL(head,getTail(head));
    PrintList(head);

    return 0;
}