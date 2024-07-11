#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<"front is: "<<q.front()<<endl;
    cout<<"back is: "<<q.back()<<endl;
    q.pop();
    cout<<"front is: "<<q.front()<<endl;
    q.pop();
    cout<<"front is: "<<q.front()<<endl;
    cout<<"size is: "<<q.size()<<endl;
    
    
}