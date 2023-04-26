#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& st,int item){
    if(st.empty()){
        st.push(item);
    }
    else
    {
        int temp = st.top();
        st.pop();
        insertAtBottom(st,item);
        st.push(temp);
    }
}

void reverseStack(stack<int>& st){
    if(!st.empty()){
        int temp = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st,temp);
    }
}

void reverseStackUsingQueue(stack<int>& st){
    queue<int> qt;

    while(!st.empty()){
        qt.push(st.top());
        st.pop();
    }

    while(!qt.empty()){
        st.push(qt.front());
        qt.pop();
    }
}


int main(){
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    //reverseStack(st);
    reverseStackUsingQueue(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}