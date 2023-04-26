#include<bits/stdc++.h>

using namespace std;
bool isOperator(char element) {
   switch (element) {
      case '+':
      case '-':
      case '/':
      case '*':
      return true;
   }
   return false;
}
string prefixtopostfix(string prefix) {
    stack<string> st;
    int length = prefix.size();
    // In prefix operands comes later after operator
    // start from length - 1
    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            // As we are starting from n first add op1 then op2
            string temp = op1+op2+prefix[i];
            st.push(temp);
        } else {
            st.push(string(1, prefix[i]));
        }
    }
    return st.top();
}
int main() {
   string prefix = "*-AB/+CD*XY";
   cout<<"Prefix expression : "<<prefix<<endl;
   cout<<"Postfix expression : " <<prefixtopostfix(prefix);
   return 0;
}