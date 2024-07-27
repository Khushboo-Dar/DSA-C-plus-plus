void dfs(int node, unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj,vector<int> &component)
{
    component.push_back(node);
    vis[node]=true;

    //rec call for every connectedd node
    for(auto i:adj[node])
    {
        if(!vis[i])
        {
            dfs(i,vis,adj,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++)
    {
 int u=edges[i][0];
 int v=edges[i][1];
 adjList[u].push_back(v);
 adjList[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int,bool> vis;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            vector<int> component;
            dfs(i,vis,adjList,component);
            ans.push_back(component);
        }
    }
    return ans;
}