#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    char ch;
    while(true)
    {
        cout<<"l.print l "<<endl<<"c.print c  "<<endl<<"q. exit"<<endl;
        cout<<"enter choice"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 'l':
                    cout<<"You have typed l "<<endl;
                    break;
            case 'c':
                    cout<<"You have typed c"<<endl;
                    break;
            case 'q':
                    cout<<"Exit ..." <<endl;
                    exit(0);
            default:
                    cout<<"Wrong choice "<<endl;
        }
    }
    return 0;
}

