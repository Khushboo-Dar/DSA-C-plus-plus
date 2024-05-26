#include<iostream>
using namespace std;
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void swapalternate(int arr[], int size)
{
    for(int i=0;i<size;i+=2)//keypoint
    {
        if(i+1<size)
        {
            swap(arr[i],arr[i+1]);

        }
    }
}
int main()
{
    int even[8]={1,2,3,4,5,6,7,8};
    int odd[5]={1,2,3,4,5};
    swapalternate(even,8);
    print(even,8);
    swapalternate(odd,5);
    print(odd,5);
}