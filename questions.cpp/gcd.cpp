#include<iostream>
using namespace std;
int gcd(int a , int b)
{
    if(a==0)
    {
        return b;
    }
    if(b==0)
    {
        return a;
    }
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        if(b>a)
        {
            b=b-a;
            
            
         }

    } cout<<"gcd is"<<a;
    return a;
}
int main()
{
    gcd(24,72);
    
}