#include<iostream>
using namespace std;
int findunique(int *arr,int size)
{
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans =ans ^ arr[i];
        cout<<ans<<" ";
    } 
    cout<<endl;
    cout<<ans;
    return ans;
}
int main()
{
    
    int arr1[7]={3,7,2,2,7,3,4};
    findunique(arr1,7);
    

}