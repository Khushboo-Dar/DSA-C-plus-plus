#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
void reverse(string s)
{int st=0;
    for(int i=0;i<s.size();i++)
    { 
        
        

        if(s[i]=='\0' || s[i]==' ')
        {
            int e=i-1;
           
            while(st<e)
            {   
                swap(s[st],s[e]);
                st++; e--;
                
            }
            st=i+1;

        
        }
    }
    cout<<s;
    
}
int main()
{
    string s;
    getline(cin,s);
    reverse(s);
    //cout<<s;
}