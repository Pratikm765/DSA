#include<bits/stdc++.h>
using namespace std;

string reversewords(string str){
    string result = "";
    stack<char> st;
    for(int i = 0; i < str.length(); i++){
        if(str[i] != ' ')
        {
            st.push(str[i]);
        }
        else
        {
            while(!st.empty()){
                result += st.top();
                st.pop();
            }
            result += ' ';
        }
    }

    while(!st.empty()){
        result += st.top();
        st.pop();
    }

    return result;
}

int main(){
    string str = "Geeks for Geeks";

    cout << reversewords(str); 
    return 0;
}