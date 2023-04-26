#include<bits/stdc++.h>

using namespace std;

void printMaxOfMin(int arr[], int n)
{
    stack<int> st;
    int leftMin[n+1] = {-1};
    
    for(int i = 0; i < n; i++){
        while(!st.empty() && (arr[st.top()] >= arr[i]))
            st.pop();

        if(!st.empty())
            leftMin[i] = st.top();

        st.push(i);
    }

    while(!st.empty())
        st.pop();

    int rightMin[n+1] = {n};
    
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && (arr[st.top()] >= arr[i]))
            st.pop();

        if(!st.empty())
            rightMin[i] = st.top();

        st.push(i);
    }

    int dist[n+1] = {0};

    // calculate dist betn left smaller and right smaller
    // that is the length where that element is min
    // find maximum of such lenghts
    for(int i=0; i < n;i++)
    {
        int len = rightMin[i] - leftMin[i] - 1;
        dist[len] = max(arr[i],dist[len]);
    }

    // fillup remaining entries in result min in n-1  
    // length cannot be less than min in n length range 
    for(int i=n-1 ; i >= 0;i--)
    {
        dist[i] = max(dist[i],dist[i+1]);
    }

    for(int i = 0 ; i < n; i++)
    {
        cout << dist[i] << " ";
    }
}


int main(){
    int arr[] = { 10, 20, 30, 50, 10, 70, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printMaxOfMin(arr, n);
    return 0;
}