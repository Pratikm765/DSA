#include<bits/stdc++.h>

using namespace std;

class Stackqueue{
    int stackSize;
    queue<int> q1;

public:

    Stackqueue(){
        stackSize = 0;
    }
    
    int top(){
        if(stackSize != 0)
            return q1.front();
        else
            return -1;
    }

    void push(int t){
        int tempSize = stackSize++;
        q1.push(t);
        while(tempSize--){
            q1.push(q1.front());
            q1.pop();
        }
    }

    void pop(){
        if(stackSize != 0)
        {
            stackSize--;
            q1.pop();
        }
        else
        {
            cout << "Stackqueue Empty\n";
        }
    }

};

int main()
{
    Stackqueue st;

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