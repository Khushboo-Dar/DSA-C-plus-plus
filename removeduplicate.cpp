#include<iostream>
#include<string>
using namespace std;
 string removeDuplicates(string s) {
        int i=0;
        int j=i+1;
        int n=s.length();
        while(i<n)
        {
            
            if(s[i]==s[j])
            {
                s.erase(i,2);
                n=s.length();
                i=0;
                j=i+1;
                
                
            }
            else{
                i++;
                j++;
                
            }

        }cout<<s;
return s;



    }
    int main()
    {
        string s;
        cout<<"enter the string: ";
        cin>>s;
        removeDuplicates(s);
        
    }