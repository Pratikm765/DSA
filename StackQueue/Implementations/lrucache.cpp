#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    int value;
    int key;
    Node* next;
    Node* prev;
    Node(int Key, int Value){
        key = Key;
        value = Value;
        next = prev = NULL;
    }
};

class List{
public:
    Node* tail;
    Node* head;
    int size;

    List(){
        tail = new Node(0,0);
        head = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNodeFront(Node* tempNode){
        Node* temp = head->next;
        head->next = tempNode;
        temp->prev = tempNode;
        tempNode->prev = head;
        tempNode->next = temp;
        size++;
    }

    void deleteNode(Node* tempNode){
        tempNode->prev->next = tempNode->next;
        tempNode->next->prev = tempNode->prev;
        size--;
    }

    void printList(){
        Node* node = head;
        while(node != NULL){
            cout << node->key << "-->";
            node = node->next;
        }
        cout << "end" << endl;
    }
};

class LRUCache{
public:
    int capacity;
    int currSize;
    map<int,Node*> NodeMap;
    List* LRUlist;
    LRUCache(int Capacity){
        capacity = Capacity;
        LRUlist = new List();
        currSize = 0;
    }

    int ReferencePage(int Key, int Value = 0){
        if(NodeMap.find(Key) != NodeMap.end()){
            Node* node = NodeMap[Key];
            node->value = Value;
            LRUlist->deleteNode(node);
            LRUlist->addNodeFront(node);
            return node->value;
        }
        else
        {
            if(currSize == capacity)
            {
                LRUlist->deleteNode(LRUlist->tail->prev);
                currSize--;
            }
            Node* node = new Node(Key,Value);
            LRUlist->addNodeFront(node);
            NodeMap[Key] = node;
            currSize++;
        }
        return Value;
    }

    void printCache(){
        LRUlist->printList();
    }
};


int main(){
    LRUCache* lru = new LRUCache(4); lru->printCache();
    lru->ReferencePage(1,10); lru->printCache();
    lru->ReferencePage(2,20); lru->printCache();
    lru->ReferencePage(3,30); lru->printCache();
    lru->ReferencePage(1,90); lru->printCache();
    lru->ReferencePage(4,40); lru->printCache();
    lru->ReferencePage(5,50); lru->printCache();

    return 0;
}