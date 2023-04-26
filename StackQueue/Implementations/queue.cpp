#include<bits/stdc++.h>
#define MAX 10

using namespace std;

template <typename T>
class Queue{
    int Front;
    int Back;
    T arr[MAX];
public:
    Queue(){
        Front = -1;
        Back = -1;
    }

    bool isEmpty(){
        if(Front == Back && Front == -1)
            return true;
        return false;
    }

    bool isFull(){
        if((Back+1)%MAX == Front)
            return true;
        return false;
    }

    T front(){
        if(isEmpty() == false)
            return arr[Front];
        else
            return -1;
    }

    T back(){
        if(isEmpty() == false)
            return arr[Back];
        else
            return -1;
    }

    void push(T t){
        if(isFull() == false)
        {
            if(isEmpty())
                Front = (Front+1)%MAX;
            Back = (Back+1)%MAX;
            arr[Back] = t;
        }
        else
        {
            cout << "Queue Full\n";
        }
    }

    void pop(){
        if(isEmpty() == false)
        {
            if(Front == Back)
                Front = Back = -1;
            else
                Front = (Front+1)%MAX;
        }
        else
        {
            cout << "Queue Empty\n";
        }
    }
};

int main()
{
    Queue<int> qt;

	while(1)
	{
		int choice;
		cout<<"0.Exit"<<endl;
		cout<<"1.push"<<endl;
		cout<<"2.pop"<<endl;
		cout<<"3.Front"<<endl;
        cout<<"4.Back"<<endl;

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
				qt.push(data);
			}
		    break;
		case 2:
			qt.pop();
			break;
		case 3:
			cout << "Top element: " << qt.front() << endl;
			break;
        case 4:
			cout << "Top element: " << qt.back() << endl;
			break;
        }
    }

    return 0;
}