#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str) {
 
  if (str.length() % 2 == 1) {
    return -1; 
  } else {
    stack<char> s;
    
    for (int i = 0; i < str.length(); i++) {
      char ch = str[i];
      if (ch == '{') {
        s.push(ch);
      } else {
        // if ch is a closing brace
        if (!s.empty() && s.top() == '{') {
          s.pop(); //(this means we have found a matching pair).
        } else {
          s.push(ch); // (this indicates an unbalanced closing brace).
        }
      }
    }
    //After processing the entire string, the stack will contain unmatched braces.
    // stack contains invalid characters
    int a = 0, b = 0;
    while (!s.empty()) {
      if (s.top() == '{') {
        b++;
      } else {
        a++;
      }
      s.pop();
    }

    // Calculate the minimum number of reversals needed
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
  }
}