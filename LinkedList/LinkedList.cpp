#include<bits/stdc++.h>

using namespace std;

class Node{
public:
    Node* next;
    int data;

    Node(int Data){
        data = Data;
        next = NULL;
    }
};

class List{
public:
    Node* head;

    List(){
        head = NULL;
    }

    void PrintList(){
        Node* node = head;
        while(node){
            cout << node->data << "-->";
            node = node->next;
        }
        cout << "NULL\n"; 
    }

    void addFirst(int Data){
        Node* node = new Node(Data);
        node->next = head;
        head = node;
    }

    void addLast(int Data){
        Node* node = new Node(Data);
        if(head == NULL)
        {
            head = node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = node;
    }

    void addAfter(int NodeData, int Data){
        Node* node = new Node(Data);
        if(head == NULL)
        {
            head = node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL && temp->data != NodeData){
            temp = temp->next;
        }
        
        if(temp->next == NULL)
            temp->next = node;
        else
        {
            node->next = temp->next;
            temp->next = node;
        }
    }

    void deleteFirst(){
        Node* node = head;
        head = node->next;
        delete node;
    }

    void deleteLast(){
        Node* temp = head;
        if(head == NULL)
            return;
        while(temp->next != NULL && temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void SearchAndDelete(int Data){
        Node* temp = head;
        if(head == NULL)
            return;

        while(temp->next != NULL && temp->next->data != Data){
            temp = temp->next;
        }

        if(temp->next != NULL && temp->next->data == Data){
            Node* node = temp->next;
            temp->next = temp->next->next;
            delete node;
        }
    }

    void deleteList(){
        while(head){
            Node* node = head;
            head = head->next;
            delete node;
        }
    }

};


int main(){
    List* ll = new List();
    while (true)
    {
        cout << "0. Exit\n";
        cout << "1. Print List\n";
        cout << "2. Add Front\n";
        cout << "3. Add Back\n";
        cout << "4. Add After Node\n";
        cout << "5. Delete Front\n";
        cout << "6. Delete Back\n";
        cout << "7. Search and Delete\n";
        cout << "8. Delete List\n";
        cout << "Enter function number: " << endl;

        int op, input;
        cin >> op;

        switch(op){
            case 0:
                exit(0);
            case 1:
            {
                ll->PrintList();
                break;
            }
            case 2:
            {
                cin >> input;
                ll->addFirst(input);
                break;
            }
            case 3:
            {
                cin >> input;
                ll->addLast(input);
                break;
            }
            case 4:
            {
                cin >> input;
                cout << "Enter Node to insert after: ";
                int input1;
                cin >> input1;
                ll->addAfter(input1,input);
                break;
            }
            case 5:
            {
                ll->deleteFirst();
                break;
            }
            case 6:
            {
                ll->deleteLast();
                break;
            }
            case 7:
            {
                cin >> input;
                ll->SearchAndDelete(input);
                break;
            }
            case 8:
            {
                ll->deleteList();
                break;
            }
                
        }

    }
    
}