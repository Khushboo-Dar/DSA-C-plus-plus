#include<iostream>
using namespace std;
bool linearsearch(int arr[],int n,int k)
{
    if(n==0)
    {
        return false;
    }
    if(arr[0]==k)
    {
        return true;
    }
    else{
        bool rempart=linearsearch(arr+1,n-1,k);
        return rempart;
    }
}
int main()
{
    int arr[5]={1,2,4,5,7};
    int n=5;
    int k=2;
    int ans=linearsearch(arr,n,k);
    cout<<"ans= "<<ans;
}