#include <bits/stdc++.h>


void topSort(int node, vector< bool> &vis, stack<int> &s, unordered_map<int, list<int>> &adj) {
    vis[node] = true;
    for (auto neigh : adj[node]) {
        if (!vis[neigh]) {
            topSort(neigh, vis, s, adj);
        }
    }
    // while returning back
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
  
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // call DFS top sort for all components
    vector<bool> vis(v);
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            topSort(i, vis, s, adj);
        }
    }
  vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}


