/*segmented sieve algo*/
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
void simplesieve(int limit,vector<int> &primes)
{
    vector<bool> isprime(limit+1,true);
    for(int p=2;p*p<=limit;p++)
    {
        if(isprime[p])
        {
            primes.push_back(p);
            for(int  i=p*p;i<=limit;i+=p)
            {
                isprime[i]=false;
            }
        }
    }
}
void segmentedsieve( int high)
{
    int limit=floor(sqrt(high))+1;
    vector<int> primes;
    simplesieve(limit, primes);
    int n=high-2+1;//n+1
    vector<bool> isprime(n,true);
    for(int i=0;i<primes.size();i++)
    {
        int currentprime=primes[i];
        int base=(2/currentprime)*currentprime;
        if(base<2)
        {
            base+=currentprime;
            for(int j=base;j<=high;j++)
            {
                isprime[j-2]=false;
            }
        }
    }

  
for(int i=2;i<=high;i++)
{
    if(isprime[i-2])
    {
        cout<<i<<" ";
    }
}
}
int main()
{
    int low=2,high;
    cout<<"enter  high";
    cin>>high;
    cout<<"primes in the range["<<low<<","<<high<<"]"<<endl;
    segmentedsieve(high);
    return 0;
}