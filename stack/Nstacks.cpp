#include <bits/stdc++.h>
using namespace std;

class NStack {
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

public:
    // Initialize the data structure
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialize top
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize next
        for (int i = 0; i < s; i++) {
            next[i] = i + 1;
        }

        // Update the last index of next
        next[s - 1] = -1;

        // Initialize freespot
        freespot = 0;
    }

    // Push x into the mth stack. Return true if pushed, else false
    bool push(int x, int m) {
        // Check for overflow
        if (freespot == -1) {
            return false;
        }

        // Find the index
        int index = freespot;

        // Insert the element into the array
        arr[index] = x;

        // Update freespot
        freespot = next[index];

        // Update next
        next[index] = top[m - 1];

        // Update top
        top[m - 1] = index;

        return true;
    }

    // Pop an element from the mth stack
    int pop(int m) {
        // Check for underflow
        if (top[m - 1] == -1) {
            return -1;
        }

        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};
