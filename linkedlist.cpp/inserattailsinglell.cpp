#include<iostream>
using namespace std;
class node{
 public:
 int data;
 node* next;
 node(int data)
 {
    this->data=data;
    this->next=NULL;
 }};
 
 void insertattail(node* &tail,int d)
 {
     node* temp=new node(d);
     tail->next=temp;
     tail=tail->next;

 }
 void traverse(node* &head)
 {
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
 }

int main()
{
    node *node1=new node(10);
    node* head=node1;
    node *tail=node1;
    traverse(head);
    insertattail(tail,12);
    traverse(head);
}