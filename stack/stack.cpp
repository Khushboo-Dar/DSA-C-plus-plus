#include<iostream>
#include<stack>
using namespace std;
int main()
{
   stack<int> s;
   s.push(2);
   s.push(3);
   cout<<"after push \n"<<s.top();
   s.pop();
   cout<<"is empty or not"<<s.empty();
   
   
   }