#include <unordered_map>

#include <queue>

#include <set>

void bfs(int n, vector<vector<int>> &adj, vector<bool> &visited,
         vector<int> &ans, int node) {

  queue<int> q;

  // Inserting Node into Queue

  q.push(node);

  // Making visited node true

  visited[node] = 1;

  while (!q.empty()) {

    // Taking front element

    int frontNode = q.front();

    q.pop();

    ans.push_back(frontNode);

    for (auto i : adj[frontNode]) {

      if (!visited[i]) {

        q.push(i);

        visited[i] = 1;
      }
    }
  }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj) {

  vector<bool> visited(n, false);

  vector<int> ans;

  bfs(n, adj, visited, ans, 0);

  return ans;
}