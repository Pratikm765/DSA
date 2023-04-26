#include<bits/stdc++.h>

using namespace std;

bool areParentethesBalanced(string str){
    stack<char> st;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            st.push(str[i]);
        else if(str[i] == ')' && st.top() == '(')
            st.pop();
        else if(str[i] == '}' && st.top() == '{')
            st.pop();
        else if(str[i] == ']' && st.top() == '[')
            st.pop();    
        else
            return false;    
    }

    if(!st.empty())
        return false;

    return true;
}


int main(){
    string exp = "{()[]";

    if (areParentethesBalanced(exp))
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;
}