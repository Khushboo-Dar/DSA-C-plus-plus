//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution {
public:
    void createMapping(int in[], map<int, vector<int>>& nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[in[i]].push_back(i);
        }
    }

    Node* solve(int in[], int pre[], int& index, int inorderStart, int inorderEnd, int n, map<int, vector<int>>& nodeToIndex, map<int, int>& usedIndex) {
        // Base case
        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }

        // Create a new node with the current value in preorder
        int element = pre[index++];
        Node* root = new Node(element);
        
        // Find the next unused position of the element
        int position = -1;
        for (int pos : nodeToIndex[element]) {
            if (usedIndex[pos] == 0) {
                position = pos;
                usedIndex[pos] = 1;
                break;
            }
        }

        // Recursively build the left and right subtrees
        root->left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex, usedIndex);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n, nodeToIndex, usedIndex);

        return root;
    }

    Node* buildTree(int in[], int pre[], int n) {
        int preOrderIndex = 0;
        map<int, vector<int>> nodeToIndex;
        map<int, int> usedIndex;
        // Create the map from node values to their indices in the inorder array
        createMapping(in, nodeToIndex, n);

        // Build the tree using the helper function
        Node* ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex, usedIndex);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends