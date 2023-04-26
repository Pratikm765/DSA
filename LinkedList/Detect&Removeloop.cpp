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

bool DetectLoop(Node* node){
    Node* slow = node;
    Node* fast = node;

    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}

void RemoveLoop(Node* node){
    Node* slow = node;
    Node* fast = node;

    // find meeting point
    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    
    // find loop length
    int loopLength = 1;
    while(slow != fast->next){
        fast = fast->next;
        loopLength++;
    }

    slow = node;
    fast = node;

    // take fast pointer forward for loop distance
    for(int i = 0; i < loopLength; i++){
        fast = fast->next;
    }

    // then start both pointers at same speed
    // if we have covered loop distance already
    // total length = loop length + distance till starting point
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    // Reach one node before starting node of loop
    while(slow != fast->next){
        fast = fast->next;
    }

    fast->next = NULL;
}

// Distance from head to begining of loop = x
// Loop length = y
// Distance from beginning of loop to meeting node = k
// Distance covered by slow pointer = x + y*m + k
// Distance covered by fast pointer = x + y*n + k
// 2 * Distance covered by slow pointer = Distance covered by fast pointer
// 2*(x+my+k) = x+ny+k  2x+2my+2k = x+ny+k x+k = (n-2m)y 
// as always n > m because of fast pointer consider x+k=iy  
// x=iy-k  x=(i+1-1)y-k x=(i-1)y+y-k 
// x = (i-1)*y + y-k
// x = rotation of loop for n-1 + distance betn meeting node to starting node of loop
void RemoveLoopFloydCycle(Node* node){
    Node* slow = node;
    Node* fast = node;

    while(slow != NULL && fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            break;
    }
    slow = node;
    if(fast == node){
        while(slow != fast->next){
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else
    {
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}
int main(){
    Node* first = new Node(7);
    first->next = new Node(5);
    first->next->next = new Node(9);
    first->next->next->next = new Node(4);
    first->next->next->next->next = new Node(3);
    first->next->next->next->next->next = first->next->next;

    if(DetectLoop(first))
    {
        cout << "Found Loop\n ";
        RemoveLoopFloydCycle(first);
        if(!DetectLoop(first))
            PrintList(first);
    }
    else
        cout << " No Loop";
}