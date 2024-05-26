#include<iostream>
using namespace std;
int main()
{  char ch;
cin>>ch;
if (ch>=97 && ch<=122)
{
    cout<<"ch is lowercase";

}
else if(ch>=65 && ch<=90)
{
    cout<<"ch is uppercase";
    
    }
    else if(ch>=48 && ch<=57)
    {
        cout<<"ch is digit";
    }
    return 0;

}






