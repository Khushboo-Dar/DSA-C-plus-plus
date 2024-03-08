#include<iostream>
using namespace std;
int fibo(int nth)
{
    int t1=0;
    int t2=1;
    cout<<t1<<" "<<t2<<endl;
    int n;
    for(int t=2;t<nth;t++)//important step
    {
 n=t1+t2;
    t1=t2;
    t2=n;
    }
    cout<<n;
    return n;
    
    
}
int main()
{
    fibo(4);
    return 0;
}