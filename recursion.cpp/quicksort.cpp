#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> & arr, int s,int e)
{
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }

    }
    int pivotindex=s+count;
    swap(arr[pivotindex],arr[s]);
    //left and right part
    int i=s;
    int j=e;
    while(i<pivotindex &&j>pivotindex)
    {
        while(arr[i]<pivot)
        {
            i++;
        }
        while(arr[j]>pivotindex)
        {
            j--;
        }
        if(i<pivotindex &&j>pivotindex){
            swap(arr[i++],arr[j--]);
        }

    }
    return pivotindex;
}
void quick(vector<int> & arr,int s,int e)
{
    //base
    if(s>=e)
    {
        return;
    }
    int p=partition(arr,s,e);
    //recursion
    quick(arr,s,p-1);
    quick(arr,p+1,e);
}
int main()
{
    vector<int> arr={3,2,4,2,2,5};
    quick(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}