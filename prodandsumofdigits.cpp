/*leetcode qs*/
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
   int prod=1;
    int sum=0;
    int ans;
    while((n) != 0)
    { 
        prod=prod*(n%10);
        sum=sum+(n%10);
         n=(n/10);

    }
    ans=prod-sum;
    cout<<ans<<endl;
}
