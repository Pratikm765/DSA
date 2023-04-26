#include<bits/stdc++.h>

using namespace std;

void printNGE(int arr[], int n){
    stack<int> st;
    st.push(arr[0]);

    for(int i = 1; i < n; i++){
        // check if current element is greater than stack elements
        while(!st.empty() && (st.top() < arr[i]))
        {
            cout << st.top() << "--->" << arr[i] << endl;
            st.pop();
        }
        st.push(arr[i]);
    }
    while(!st.empty()){
        cout << st.top() << "---> -1"  << endl;
        st.pop();
    }
}

int main(){
    int arr[] = { 11, 13, 21, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printNGE(arr, n);
    return 0;
}