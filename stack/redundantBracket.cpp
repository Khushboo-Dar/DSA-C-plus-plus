#include <bits/stdc++.h>


bool findRedundantBrackets(string &s) {
  stack<char> st;
  for (int i = 0; i < s.length(); i++) {
    char ch = s[i];
    if (ch == '(' || ch == '+' || ch == '*' || ch == '-' || ch == '/') {
      st.push(ch);
    } else if (ch == ')') {
      bool isRedundant = true;
      while (st.top() != '(') {
        char top = st.top();
        if (top == '+' || top == '*' || top == '-' || top == '/') {
          isRedundant = false;
        }
        st.pop();
      }
      st.pop(); // pop the opening bracket
      if (isRedundant) {
        return true;//if its true it won't go further
      }
    }
  }
  return false;
}
