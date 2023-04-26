#include <bits/stdc++.h>
using namespace std;

void reverseQueueUsingStack(queue<int>& qt){
    stack<int> st;

    while(!qt.empty()){
        st.push(qt.front());
        qt.pop();
    }

    while(!st.empty()){
        qt.push(st.top());
        st.pop();
    }
}

int main(){
    queue<int> qt;
    qt.push(10);
    qt.push(20);
    qt.push(30);
    qt.push(40);

    reverseQueueUsingStack(qt);

    while(!qt.empty()){
        cout << qt.front() << " ";
        qt.pop();
    }

    return 0;
}
