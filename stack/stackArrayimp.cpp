#include<iostream>
#include<stack>
using namespace std;
class Stack{
    public:
 int *arr;
 int top;
 int size;
 //constructor
Stack (int size)
{
    this->size = size;
    arr = new int[size];
    top =-1;

}


void push(int element)
{
    if(size-top >1)
    {
        top++;
        arr[top]=element;
    }
    else{
        cout<<"Stack overflow"<<endl;
    }

}
void pop()
{
  if(top<0)
  {
    cout<<"stack underflow";

  }
  else{
    top--;
  }

}
int peek()
{
    if(top>=0)
    {
        return arr[top];
    }
    else{
        cout<<"stack is empty"<<endl;
        return 0;
    }

}
bool isEmpty()
{
   if(top==-1)
   {
    cout<<"stack empty"<<endl;
    return 1;
   }
   else{
    cout<<"stack not empty"<<endl;
    return 0;
   }
}
};
int main()
{
    Stack st(5);
     st.push(2);
    st.push(3);
   st.push(4);
    st.push(5);
    cout<<"top is"<<st.peek()<<endl;
    st.pop();
     cout<<"top is"<<st.peek()<<endl;
    cout<<st.isEmpty()<<endl;
}