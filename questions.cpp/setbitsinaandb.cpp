#include<iostream>
using namespace std;
unsigned int setbits(unsigned int a, unsigned int b)
{
    int n1=0;
    int n2=0;
    
    while(a)
    {
        n1+=a&1;
        a>>=1;

    }
    cout<<n1<<endl;
    while(b)
    {
        n2+=b&1;
        b>>=1;
    }
    cout<<n2<<endl;
    int n=n1+n2;
    cout<<n;
    return n;

}
int main()
{
    setbits(2,3);
    return 0;
    
}
