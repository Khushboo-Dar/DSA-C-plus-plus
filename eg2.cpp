/*#include<iostream>
using namespace std;
int hammingweight(int x)
{
    int count =0;
    while(x)
    {
        count+=x&1;
        x>>1;
    }
    cout<<count;
    return count;
}
int main()
{ cout<<" and is ";
int a = 4 & 1;
cout<<a;
    hammingweight(5);
}*/
#include <iostream>
using namespace std;
class Box{ 
       double width;   
        public:    
        friend void printWidth( Box box ); 
           void setWidth( double wid );
           };
           void Box::setWidth( double wid ){ 
               width = wid;
               }
               void printWidth( Box box ){  
                  box.width = box.width * 2;   
                   cout << "Width of box : " << box.width << endl;
                   }
                   int main( ){
                        Box box;
                            box.setWidth(10.0);  
                              printWidth( box );  
                                return 0;
                                }
