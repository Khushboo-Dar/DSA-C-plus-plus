/*return true if number of occurrence is unique otherwise false*/
#include<iostream>

using namespace std;
int unique(int *arr ,int size)
{
    int ans=0;
    for(int i=0;i<size;i++)
    {
        ans=ans^arr[i];
    }
    cout<<ans;
    if(ans==0)
    { cout<<"false";
        return 0;
    }
    else 
    { cout<<"true";
        return 1;
    }

}
int main()
{
    int arr1[6]={1,2,2,1,3,3};
    unique(arr1,6);
}

