#include<bits/stdc++.h>

using namespace std;

vector<int> stockSpan(vector<int> stocks){
    stack<int> st;
    vector<int> spans(stocks.size());
    st.push(0);
    spans[0] = 1;

    for(int i = 1; i < stocks.size(); i++){
        while(!st.empty() && (stocks[st.top()] <= stocks[i])){
            st.pop();
        }
        spans[i] = st.empty() ? (i+1) : (i-st.top());
        st.push(i);
    }
    return spans;
}

int main(){
    vector<int> stocks = { 10, 4, 5, 90, 120, 80 };
    vector<int> spans =  stockSpan(stocks);

    for(int i : stocks){
        cout << i << " ";
    }
    cout << endl;
    for(int i : spans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}