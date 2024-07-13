#include <vector>
#include <map>
#include <queue>
#include<iostream>
#include<bits\stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node* root) {
        // Nested map to store nodes at each horizontal distance and level.
        map<int, map<int, vector<int>>> nodes;
        // Queue for level order traversal (BFS).
        queue<pair<Node*, pair<int, int>>> q;
        // Result vector to store the final vertical order traversal.
        vector<int> ans;
        
        // If the tree is empty, return an empty vector.
        if (root == NULL)
            return ans;
        
        // Start BFS with the root node at horizontal distance 0 and level 0.
        q.push(make_pair(root, make_pair(0, 0)));
        
        // Perform BFS.
        while (!q.empty()) {
            // Get the front node and its horizontal distance and level.
            pair<Node*, pair<int, int>> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            // Store the node's value in the map.
            nodes[hd][lvl].push_back(frontNode->data);
            
            // If the node has a left child, enqueue it with hd-1 and lvl+1.
            if (frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            
            // If the node has a right child, enqueue it with hd+1 and lvl+1.
            if (frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
        
        // Traverse the map to construct the result.
        for (auto i: nodes) {
            for (auto j: i.second) {
                for (auto k: j.second) {
                    ans.push_back(k);
                }
            }
        }
        
        // Return the final vertical order traversal.
        return ans;
    }
};
