#include <bits/stdc++.h>
using namespace std;

/*
    This is the signature of the helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will return "true" if the person having
    id 'A' knows the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
    stack<int> st;

    // Step 1: Push all people to the stack
    for(int i = 0; i < n; i++) {
        st.push(i);
    }

    // Step 2: Narrow down to one candidate
    while(st.size() > 1) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        if(knows(a, b)) {
            // a knows b, so a cannot be a celebrity
            st.push(b);
        } else {
            // a does not know b, so b cannot be a celebrity
            st.push(a);
        }
    }

    int candidate = st.top();

    // Step 3: Verify the candidate
    for(int i = 0; i < n; i++) {
        if(i != candidate) //This condition ensures that the candidate does not check itself.
        {
            if(knows(candidate, i) || !knows(i, candidate)) {
                return -1;
            }
        }
    }

    return candidate;
}
