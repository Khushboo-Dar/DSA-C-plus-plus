#include<iostream>
using namespace std;
int main()
{

    int totalamount;
    cout<<"enter amount"<<endl;
    cin>>totalamount;

    int notes;
    while(true)
    {
        cout<<"enter note type";

    
    cin>>notes;
    switch(notes)
    {
       case 100:
       int hnotes;
       hnotes=totalamount/100;
       cout<<"hnotes="<<hnotes<<endl;
       totalamount=totalamount%100;
       break;
       case 50:
       int fnotes;
       fnotes=totalamount / 50;
        cout<<"fnotes="<<fnotes<<endl;
       totalamount=totalamount%50;
       break;
       case 20:
       int ttnotes;
       ttnotes=totalamount/20;
        cout<<"ttnotes="<<ttnotes<<endl;
       totalamount=totalamount%20;
       break;
       case 10:
       int tnotes;
       tnotes=totalamount/10;
        cout<<"tnotes="<<tnotes<<endl;
       totalamount=totalamount%10;
       
       
       
       exit(0);
    }
    }
    
    return 0;
}