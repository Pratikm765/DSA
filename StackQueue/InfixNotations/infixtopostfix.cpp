#include<bits/stdc++.h>

using namespace std;

bool isOperand(char c){
    if((c >= 'a' && c <= 'z')||
       (c >= 'A' && c <= 'Z')||
       (c >= '0' && c <= '9'))
       return true;
    return false;
}

int Prec(char ch)
{
    switch (ch) {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
 

string infixtopostfix(string infix)
{
    string postfix = "";
    stack<char> st;

    for(int i = 0; i < infix.length(); i++){
        if(isOperand(infix[i]))
        {
            // add to postfix when character is letter or number
            postfix+=infix[i];
        }
        else if(infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
            // got bracket end, add to postfix till we get (
            while(!st.empty() && st.top() != '(')
            {
                postfix+=st.top();
                st.pop();
            }
            // remove ( from stack
            st.pop();
        }
        else
        {
            // check precedence of operator 
            while(!st.empty() && Prec(infix[i]) <= Prec(st.top()))
            {
                postfix+=st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while(!st.empty()){
        // store remaining operators in stack
        postfix+=st.top();
        st.pop();        
    }

    postfix+='\0';

    return postfix;
}

int main(){
    // string infix = "a+b*c+d"; //abc*+d+
    string infix = "x^y/(5*z)+2";//xy^5z*/2+

    cout << infixtopostfix(infix);

}