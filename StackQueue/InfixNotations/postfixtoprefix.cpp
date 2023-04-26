#include<bits/stdc++.h>

using namespace std;
bool isOperator(char element) {
   switch (element) {
      case '+':
      case '-':
      case '/':
      case '*':
      case '^':
      return true;
   }
   return false;
}
string postfixtoprefix(string postfix) {
    stack<string> st;
    int length = postfix.size();
    // begin from 0 as in postfix operands comes before operator
    for (int i = 0; i < length; i++) {
        if (isOperator(postfix[i])) {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            // As we are starting from 0 first add op2 then op1
            string temp = postfix[i]+op2+op1;
            st.push(temp);
        } else {
            st.push(string(1, postfix[i]));
        }
    }
    return st.top();
}
int main() {
   string postfix = "xy^5z*/2+";// +/^xy*5z2
   cout<<"postfix expression : "<<postfix<<endl;
   cout<<"Prefix expression : " <<postfixtoprefix(postfix);
   return 0;
}