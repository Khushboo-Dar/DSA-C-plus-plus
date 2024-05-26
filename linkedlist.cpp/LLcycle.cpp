
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };



Node *firstNode(Node *head)
{
    //    Write your code here.
    if(head==NULL || head->next==NULL)
    {
        return NULL;
    }
    //floyd's algo
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
            slow=slow->next;
            fast=fast->next->next;
        
        if(slow==fast)
        {
           slow=head;
           while(slow!=fast)
           {
               slow=slow->next;
               fast=fast->next;
           }
           return slow;
        }
    }
    return NULL;
}