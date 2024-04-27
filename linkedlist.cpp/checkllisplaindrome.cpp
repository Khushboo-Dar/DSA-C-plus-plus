#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<vector>
using namespace std;
/*linked list node*/
struct  Node{
    int data;
    struct  Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
/*to check if linked list is palindrome METHOD 1 ; TC = O(N), SC = O(N) */
// class Solution{
//     private:
    
//         bool checkPalindrome(vector<int> arr)
//         { int n=arr.size();
//             int start=0;
//             int end=n-1;
//             while(start<=end)
//             {
//                 if(arr[start]!=arr[end])
//                 {
//                     return 0;
//                 } 
//                 start++;
//                 end--;
               
//             } return 1;
//         }
    
//   public:
//     //Function to check whether the list is palindrome.
//     bool isPalindrome(Node *head)
//     {
//         Node* temp=head;
//         vector<int> arr;
//         while(temp!=NULL)
//         {
//             arr.push_back(temp->data);
//             temp=temp->next;
//         }
//         return checkPalindrome(arr);
//     }
// };


/*METHOD 2 ; TC = O(N) , SC = O(1) */

class Solution{
    private:
    Node* getMid(Node* head)
    {
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
        }
        return slow;
    }
        
        Node* reverse(Node* head)
        {
            Node* curr=head;
            Node* prev=NULL;
            Node* next=NULL;
            while(curr!=NULL)
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        if(head->next==NULL)
    
        {
            return true;
        }
        Node* middle=getMid(head);
        Node* temp=middle->next;
        middle->next=reverse(temp);
        
        //compare
        Node* head1=head;
        Node* head2=middle->next;
        while(head2!=NULL)
        {
            if(head1->data!=head2->data)
            {
                return false;
            }
            head1=head1->next;
            head2=head2->next;
            
        }
        return true;
    }
};



int main()
{
    int T,i,n,l,firstdata;
    cin>>T;//test cases
    while(T--)
    {
        struct Node* head=NULL, *tail=NULL;
        cin>>n;
        cout<<"n is"<<n<<endl;
        cin>>firstdata;
        head=new Node(firstdata);
        tail=head;
        //taking remaining data of ll
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next=new Node(l);
            tail=tail->next;

        }
        Solution obj;
        cout<<obj.isPalindrome(head)<<endl;
        
    }
    return 0;
}