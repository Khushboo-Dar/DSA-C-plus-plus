#include<iostream>
#include<vector>
using namespace std;
int findduplicate(vector<int> &arr)
{
    int ans=0;
    for(int i=0;i<arr.size();i++)
    {
        ans=ans^arr[i];
    }
    for(int i=1;i<arr.size();i++)
    {
        ans = ans^i;
    }
    cout<<ans<<endl;
    return ans;
}
int main()
{ vector<int> arr1(5);
for(int i=0;i<5;i++)
{
 cin>>arr1[i];
}
    findduplicate(arr1);
    return 0;
}