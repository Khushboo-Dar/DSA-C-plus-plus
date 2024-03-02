#include<iostream>
using namespace std;
int ap(int n)
{
    
    
    int ap=(3*n)+7;
    int a_n=10+3*(n-1);
    cout<<a_n;
    return a_n;
}
int main()
{
    ap(3);
    return 0;
}