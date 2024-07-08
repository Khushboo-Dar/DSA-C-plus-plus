#include <bits/stdc++.h> 
class TwoStack {

public:

    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this->size=s;
        top1=-1;
        top2=s;
        arr=new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top2-top1>1)
        {
            top1++;
            arr[top]=num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2-top1>1)
        {
            top2--;
            arr[top]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1>=0)
        { int ans=arr[top];
            top1--;
return ans;
        }
        else{
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
        if(top2<size) //empty case
        { int ans=arr[top];
            top2++;
return ans;
        }
        else{
            return -1;
        }
    }
};
