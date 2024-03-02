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
 void insertathead(node* &head,int d)
 {
    //new node
    node* temp=new node(d);
    temp->next=head;
    head=temp;
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
    traverse(head);
    insertathead(head,12);
    traverse(head);
}