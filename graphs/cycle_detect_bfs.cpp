
#include<unordered_map>
#include<queue>
#include<list>


bool isCyclebfs(int src, unordered_map<int, bool> &vis,unordered_map<int,list<int>> &adj)
{
    unordered_map<int,int> parent;
    parent[src]=-1;
    vis[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto neighbour :adj[front])
        {
            if(vis[neighbour]==true && neighbour !=parent[front])
            {
                return true;
            }
            else if(!vis[neighbour])
            {
                q.push(neighbour);
                vis[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
return false;
}



string cycleDetection (vector<vector<int>>& edges, int n, int m)
{  unordered_map<int,list<int>> adj;

    for(int i=0;i<m;i++)
    {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);

    }
    //to handle disconn comp
    unordered_map<int,bool> vis;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            bool ans=isCyclebfs(i,vis,adj);
            if(ans==1)
            {
                return "Yes";
            }

        }
        
    }return "No";
}
