#include<iostream>
using namespace std;
bool ispossible(int arr[], int n, int k, int mid)
{
    int paintercount=1;
    int boards=0;
    for(int i=0;i<n;i++)
    {
        if(boards+arr[i]<=mid)
        {
            boards+=arr[i];
        }
        else{
            paintercount++;
        if(paintercount>k || arr[i]>mid)
        {
            return false;
        }
        else{
            boards=arr[i];
          
        }}
    }  return true;
}
int paint(int arr[],int n,int k)
{
    int s=0;
    
    
    int sum=0;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int e=sum;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(ispossible(arr,n,k,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
         mid=s+(e-s)/2;
    }cout<<"ans= "<<ans;
    return ans;
    
}
int main()
{
    int arr[8]={6 ,5 ,6 ,10, 9,2, 3 ,5 };
    paint(arr,8,2);
    
}