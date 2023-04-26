#include<bits/stdc++.h>

using namespace std;

int getMaxArea(int arr[], int n){
    int maxarea = 0;
    int curarea = 0;
    stack<int> st;
    int i = 0; 

    while(i < n){
        if(st.empty() || (arr[st.top()] <= arr[i]))
        {
            st.push(i++);
        }
        else
        {
            int tp = st.top();
            st.pop();
            // calculate area between top and second last top
            curarea = arr[tp] * (st.empty() ? i : i-st.top()-1);

            if(curarea > maxarea)
            {
                maxarea = curarea;
            }
        }
    }

    while(!st.empty())
    {
        int tp = st.top();
        st.pop();
        curarea = arr[tp] * (st.empty() ? i : i-st.top()-1);

        if(curarea > maxarea)
        {
            maxarea = curarea;
        }
    }

    return maxarea;
}


int main(){
    int hist[] = { 6, 2, 5, 4, 5, 1, 6 };
    int n = sizeof(hist) / sizeof(hist[0]);
  
    // Function call
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}