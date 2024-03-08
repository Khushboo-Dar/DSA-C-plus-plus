#include <bits/stdc++.h> 
#include <iostream>
#include<cmath>
using namespace std;

int main() {
    //Write your code here
int S,E;
cin>>S>>E;
int W;
cin>>W;

  for (int F=S;F<=E;F=F+W)
  {
float C=(F-32)*5.0/9.0;
 if(C>=0)
 { 
   cout<<F<<" "<<floor(C)<<endl;
     
 }
 else {
   cout<<F<<" "<<ceil(C)<<endl;
 }
 

  }





    return 0;
}