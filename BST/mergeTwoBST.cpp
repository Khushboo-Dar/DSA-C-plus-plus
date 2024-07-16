#include <vector>
using namespace std;

/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

// void inorder(TreeNode* root, vector<int> &in)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     inorder(root->left, in);
//     in.push_back(root->data);
//     inorder(root->right, in);
// }

// vector<int> mergeArray(const vector<int>& a, const vector<int>& b)
// {
//     vector<int> ans(a.size() + b.size());
//     int i = 0, j = 0, k = 0;
//     while (i < a.size() && j < b.size())
//     {
//         if (a[i] < b[j])
//         {
//             ans[k++] = a[i++];
//         }
//         else
//         {
//             ans[k++] = b[j++];
//         }
//     }
//     while (i < a.size())
//     {
//         ans[k++] = a[i++];
//     }
//     while (j < b.size())
//     {
//         ans[k++] = b[j++];
//     }
//     return ans;
// }

// TreeNode* inorderToBST(int s, int e, const vector<int>& in)
// {
//     // base case
//     if (s > e)
//     {
//         return NULL;
//     }
//     int mid = (s + e) / 2;
//     TreeNode* root = new TreeNode(in[mid]);
//     root->left = inorderToBST(s, mid - 1, in);
//     root->right = inorderToBST(mid + 1, e, in);
//     return root;
// }

//convert to dll
void convertToSortedDLL(TreeNode * root, TreeNode* & head)
{
    //base case
    if(root==NULL)
    {
        return;
    }
    convertToSortedDLL(root->right,head);

    root->right=head;
    if(head!=NULL)
    {
        head->left=root;
    }
    head=root;

    convertToSortedDLL(root->left,head);
}
// merge two sroted ll
TreeNode mergeLL(TreeNode* head1, TreeNode* head2)
{
    TreeNode* head=NULL;
    TreeNode* tail=NULL;
    while(head1!=NULL  && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            if(head==NULL)
            {
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
              tail->right=head1;
              head1->left=tail;
              tail=head1;
              head1=head1->right;
            }
        }
        else{
            if(head==NULL)
            {
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
              tail->right=head2;
              head2->left=tail;
              tail=head2;
              head2=head2->right;
            }
        }
    }
    while(head1!=NULL)
    {
        tail->right=head1;
              head1->left=tail;
              tail=head1;
              head1=head1->right;
         
    }
    while(head2!=NULL)
    {
        tail->right=head2;
              head2->left=tail;
              tail=head2;
              head2=head2->right;
         
    }
    return head;
}

//ll to bst
int count(TreeNode* head)
{
    int cnt=0;
    TreeNode* temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->right;

    }
    return cnt;
}
TreeNode* sortedLLtoBST(TreeNode* & head, int n )
{
    //base case
    //n is no of nodes
    if(n<=0 || root==NULL)
    {
        return NULL;
    }
    TreeNode* left=sortedLLtoBST(head,  n/2);
    TreeNode* root=head;
    root->left=left;
    head=head->next;
    root->right=sortedLLtoBST(head,n-n/2 -1);
    return root;
}


vector<int> mergeBST(TreeNode* root1, TreeNode* root2)
{
   /* vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);
    
    return mergeArray(bst1, bst2);*/

    //1. bst to sorted ll
TreeNode* head1=NULL;
convertToSortedDLL(root1, head1);
head1->left=NULL;

TreeNode* head2=NULL;
convertToSortedDLL(root2, head2);
head2->left=NULL;

//2. merge sorted ll
TreeNode* head=mergeLL(head1, head2);

//3. sorted ll to bst
return sortedLLtoBST(head, count(head));





}