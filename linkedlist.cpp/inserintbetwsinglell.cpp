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
 }void insertattail(node* &tail,int d)
 {
     node* temp=new node(d);
     tail->next=temp;
     tail=tail->next;

 }
 void inseratposition(node* &tail,node* &head,int position,int d)
 {//insert at start
    if(position==1)
    {
        insertathead(head,d);
        return;
    }
    node* temp=head;
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL)//inserting at last
    {
        insertattail(tail,d);
        return;
    }
    node* nodetoinsert=new node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;

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
   inseratposition(tail,head,3,22);
    traverse(head);
    cout<<"head"<<head->data<<endl;
    cout<<"tail"<<tail->data<<endl;
}