#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int>& st){
    stack<int> tempStack;
    while(!st.empty()){
        int temp = st.top();
        st.pop();

        while(!tempStack.empty() && tempStack.top() > temp)
        {
            st.push(tempStack.top());
            tempStack.pop();
        }

        tempStack.push(temp);
    }
    return tempStack;
}

int main(){
    stack<int> st;
    st.push(34);
    st.push(3);
    st.push(98);
    st.push(23);

    stack<int> sst = sortStack(st);

    while(!sst.empty()){
        cout << sst.top() << " ";
        sst.pop();
    }

    return 0;
}