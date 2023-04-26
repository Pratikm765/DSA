#include<bits/stdc++.h>
using namespace std;

string reverseString(string str){
    string result = "";
    stack<int> st;

    for(int i = 0; i < str.length(); i++){
        st.push(str[i]);
    }

    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    return result;
}

int main(){
    string str = "DataStructures";
    cout << reverseString(str);
    return 0;
}