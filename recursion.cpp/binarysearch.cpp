#include<iostream>
using namespace std;
bool binarysearch(int arr[],int s,int e,int k)
{
    //int s=0;
    //int e=n-1;
    int mid=s+(e-s)/2;
    if(s>e)
    {
        return false;

    }
    if(arr[mid]==k)
    {
        return true;
    }
    if(arr[mid]<k)
    {
        binarysearch(arr,mid+1,e,k);
    }
    if(arr[mid>k])
    {
        binarysearch(arr,s,mid-1,k);
    }
}
int main(){
    int arr[5]={1,3,4,6,7};
    int n=sizeof(arr);
    int s=0;
    int e=n-1;
    int k=7;
    int ans=binarysearch(arr,s,e,k);
    cout<<"ans= "<<ans;
}