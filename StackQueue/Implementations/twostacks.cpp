#include<bits/stdc++.h>
#define MAX 10
using namespace std;

class TwoStacks{
    int top1;
    int top2;
    int arr[MAX];

public:

    TwoStacks(){
        top1 = -1;
        top2 = MAX;
    }
    
    int top(int sNo){
        if(sNo == 1 && top1 != -1)
            return arr[top1];
        else if(sNo == 2 && top2 != MAX)
            return arr[top2];
        else
            return -1;
    }

    void push(int sNo, int t){
        if((top2 - top1) > 1)
        {
            if(sNo == 1)
                arr[++top1] = t;
            else if(sNo == 2)
                arr[--top2] = t;
        }
        else
            cout << "Stacks full\n";
    }

    void pop(int sNo){
        if(sNo == 1 && top1 != -1)
            top1--;
        else if(sNo == 2 && top2 != MAX)
            top2++;
    }

};

int main()
{
    TwoStacks st;

	while(1)
	{
		int choice;
		cout<<"0.Exit"<<endl;
		cout<<"1.stack1 push"<<endl;
        cout<<"2.stack2 push"<<endl;
		cout<<"3.stack1 pop"<<endl;
        cout<<"4.stack2 pop"<<endl;
		cout<<"5.stack1 top"<<endl;
        cout<<"6.stack2 top"<<endl;

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
				st.push(1,data);
			}
		    break;
		case 3:
			st.pop(1);
			break;
		case 5:
			cout << "Top element: " << st.top(1) << endl;
			break;
		case 2:
			{
				int data;
				cout << "Enter data: ";
				cin >> data;
				st.push(2,data);
			}
		    break;
		case 4:
			st.pop(2);
			break;
		case 6:
			cout << "Top element: " << st.top(2) << endl;
			break;
        }
    }

    return 0;
}