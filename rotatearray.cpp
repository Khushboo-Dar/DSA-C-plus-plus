#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void rotate(vector<int> arr,int n,int k)
{
     for(int i=0;i<n;i++)
     {
          arr[(i+k)%n]=arr[i];
     }
     for(int i=0;i<n;i++)
     {
        cout<<arr[i]<<" ";
     }
}
int main()
{
    vector<int> arr={ 1, 2, 3 ,4, 5};
    rotate(arr,5,2);
}