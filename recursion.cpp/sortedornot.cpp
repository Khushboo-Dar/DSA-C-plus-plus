#include<iostream>
using namespace std;
bool issorted(int arr[],int size)
{
    if(size==0 || size==1)

    { cout<<"sorted";
        return true;
    }
    if(arr[0]>arr[1])
    { cout<<"not sorted";
        return false;
    }
    else{
        bool ans=issorted(arr+1,size-1);
        return ans;
    }
}
int main()
{
    int arr[5]={2,4,3,5,1};
    int size=5;
    issorted(arr,size);
    }