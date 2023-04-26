#include<bits/stdc++.h>

using namespace std;

void printNGFreq(int arr[], int n, vector<int> freq){
    stack<int> st;
    
    int result[n];
    st.push(0);

    for(int i = 1; i < n; i++){
        // check if current element is next frequent  
        // element for stack elements
        while(!st.empty() && (freq[arr[st.top()]] < freq[arr[i]]))
        {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        result[st.top()] = -1;
        st.pop();
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << "-->" << result[i] <<endl;
    }
}

int main(){
    int arr[] = { 1, 1, 2, 3, 4, 2, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxEle = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        maxEle = max(maxEle,arr[i]);
    }

    vector<int> freq(maxEle+1,0);
    for(int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    printNGFreq(arr, n, freq);
    return 0;
}