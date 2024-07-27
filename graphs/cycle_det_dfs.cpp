
#include<unordered_map>
#include<queue>
#include<list>
bool isCycledfs(int node, int parent,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj)

{
    vis[node]=true;
    for(auto neighbour: adj[node])
    {
        if(!vis[neighbour])
        {
            bool cycleDetected=isCycledfs(neighbour,node,vis,adj);
            if(cycleDetected)
            {
                return true;
            }
            
        }
        else if(neighbour!=parent)
        {
            return true; //cyle pres
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
            bool ans=isCycledfs(i,vis,adj);
            if(ans==1)
            {
                return "Yes";
            }

        }
        
    }return "No";
}
