#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    Node* prev;
    Node* next;
    int key, value, _count;

    Node(int Key, int Value){
        key = Key;
        value = Value;
        _count = 1;
        prev = NULL;
        next = NULL;
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
};

class LFUCache{
public:
    map<int,Node*> NodeMap;
    map<int,List*> FreqListMap;
    int currSize;
    int capacity;
    int minFreq;

    LFUCache(int cap){
        capacity = cap;
        minFreq = 0;
        currSize = 0;
    }

    void updateFreqListMap(Node* node){
        NodeMap.erase(node->key);
        FreqListMap[node->_count]->deleteNode(node);

        if(node->_count == minFreq && FreqListMap[minFreq]->size == 0){
            minFreq++;
        }

        List* nextHighFreqList;
        if(FreqListMap.find(minFreq) != FreqListMap.end()){
            nextHighFreqList = FreqListMap[minFreq];
        }
        else
        {
            nextHighFreqList = new List();
        }

        node->_count += 1;
        nextHighFreqList->addNodeFront(node);
        FreqListMap[node->_count] = nextHighFreqList;
        NodeMap[node->key] = node;
    }

    int getNode(int Key){
        if(NodeMap.find(Key) != NodeMap.end()){
            Node* node = NodeMap[Key];
            updateFreqListMap(node);
            return node->value;
        }
        return -1;
    }

    void putNode(int Key,int Value){
        if(capacity == 0){
            return;
        }
        if(NodeMap.find(Key) != NodeMap.end())
        {
            Node* node = NodeMap[Key];
            node->value = Value;
            updateFreqListMap(node);
        }
        else
        {
            if(currSize == capacity){
                List* list = FreqListMap[minFreq];
                NodeMap.erase(list->tail->prev->key);
                FreqListMap[minFreq]->deleteNode(list->tail->prev);
                currSize--;
            }

            Node* node = new Node(Key,Value);
            List* listFreq;
            if(FreqListMap.find(node->_count) != FreqListMap.end()){
                listFreq = FreqListMap[node->_count];
            }
            else
            {
                listFreq = new List();
            }
            listFreq->addNodeFront(node);

            NodeMap[Key] = node;
            FreqListMap[node->_count] = listFreq;

            currSize++;
            minFreq = node->_count;
        }
    }

};



int main(){

    LFUCache* lfu;
    string operations[] = {"LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"};
    int a[][2] = {{2,-1}, {1, 1}, {2, 2}, {1,-1}, {3, 3}, {2,-1}, {3,-1}, {4, 4}, {1,-1}, {3,-1}, {4,-1}};


    for(int i = 0; i < 11; i++){
        if(operations[i] == "LFUCache"){
            lfu = new LFUCache(a[i][0]);
        }
        else if(operations[i] == "put"){
            lfu->putNode(a[i][0],a[i][1]);
        }
        else if(operations[i] == "get"){
            cout << lfu->getNode(a[i][0]) << endl;
        }
    }
    return 0;
}

// Insert into Cache one by one
// If it becomes full then remove least frequently used.
// If there are multiple with same frequency then  remove least recently used.
// LFUCache lfu = new LFUCache(2);
// lfu.put(1, 1);   // cache=[1,_], cnt(1)=1            // FreqListMap[1]: 1
// lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1  // FreqListMap[1]: 2->1
// lfu.get(1);      // return 1
//                  // cache=[1,2], cnt(2)=1, cnt(1)=2  // FreqListMap[1]: 2   FreqListMap[2]: 1
// lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
//                  // cache=[3,1], cnt(3)=1, cnt(1)=2  // FreqListMap[1]: 3   FreqListMap[2]: 1
// lfu.get(2);      // return -1 (not found)            // Not Found
// lfu.get(3);      // return 3                         
//                  // cache=[3,1], cnt(3)=2, cnt(1)=2  // FreqListMap[1]:     FreqListMap[2]: 3->1
// lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//                  // cache=[4,3], cnt(4)=1, cnt(3)=2  // FreqListMap[1]: 4   FreqListMap[2]: 3
// lfu.get(1);      // return -1 (not found)            // Not Found
// lfu.get(3);      // return 3
//                  // cache=[3,4], cnt(4)=1, cnt(3)=3  // FreqListMap[1]: 4   FreqListMap[2]:      FreqListMap[3]: 3
// lfu.get(4);      // return 4
//                  // cache=[4,3], cnt(4)=2, cnt(3)=3  // FreqListMap[1]:     FreqListMap[2]: 4    FreqListMap[3]: 3