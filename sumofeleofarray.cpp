#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,6};
    int sum=0;
    for(int i=0;i<(sizeof(arr)/sizeof(int));i++)
    {
      sum=sum+arr[i];

    }
    cout<<sum;
    return 0;
}