#include<bits/stdc++.h>
#define MAX 10

using namespace std;

template <typename T>
class Stack{
    int Top ;
    T arr[MAX];

public:

    Stack(){
        Top = -1;
    }

    bool isEmpty(){
        if(Top == -1)
            return true;
        return false;
    }

    bool isFull(){
        if(Top == MAX)
            return true;
        return false;
    }

    T top(){
        if(isEmpty() == false)
            return arr[Top];
        else
            return -1;
    }

    void push(T t){
        if(isFull() == false)
        {
            arr[++Top] = t;
        }
        else
        {
            cout << "stack Full\n";
        }
    }

    void pop(){
        if(isEmpty() == false)
        {
            Top--;
        }
        else
        {
            cout << "stack Empty\n";
        }
    }
};

int main()
{
    Stack<int> st;

	while(1)
	{
		int choice;
		cout<<"0.Exit"<<endl;
		cout<<"1.push"<<endl;
		cout<<"2.pop"<<endl;
		cout<<"3.top"<<endl;

		cout<<"Enter Your Choice:";
		cin>>choice;
		switch(choice)
		{
		case 0:
			exit(0);
		case 1:
			{
				int data;
				cout << "Enter data: ";
				cin >> data;
				st.push(data);
			}
		    break;
		case 2:
			st.pop();
			break;
		case 3:
			cout << "Top element: " << st.top() << endl;
			break;
        }
    }

    return 0;
}