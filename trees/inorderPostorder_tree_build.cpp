//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:
void createMapping(int in[], map<int, vector<int>>& nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[in[i]].push_back(i);
        }
    }

    Node* solve(int in[], int post[], int& index, int inorderStart, int inorderEnd, int n, map<int, vector<int>>& nodeToIndex, map<int, int>& usedIndex) {
        // Base case
        if (index <0 || inorderStart > inorderEnd) {
            return NULL;
        }

        // Create a new node with the current value in preorder
        int element = post[index--];
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
        root->right = solve(in, post, index, position + 1, inorderEnd, n, nodeToIndex, usedIndex);
        root->left = solve(in, post, index, inorderStart, position - 1, n, nodeToIndex, usedIndex);
        

        return root;
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int n, int in[], int post[]) {
        // Your code here
         int postOrderIndex =n-1;
        map<int, vector<int>> nodeToIndex;
        map<int, int> usedIndex;
        // Create the map from node values to their indices in the inorder array
        createMapping(in, nodeToIndex, n);

        // Build the tree using the helper function
        Node* ans = solve(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex, usedIndex);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends