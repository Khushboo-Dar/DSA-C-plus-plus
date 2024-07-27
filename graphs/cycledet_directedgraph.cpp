#include<unordered_map>
#include<list>


bool checkCycleDFS(int node, unordered_map<int,bool> &vis , unordered_map<int,bool> &dfsvis,unordered_map<int,list<int>> &adj)
{
   vis[node]=true;
   dfsvis[node]=true;
   for(auto neigh: adj[node])
   {
     if(!vis[neigh])
     {
       bool cycledetected=checkCycleDFS(neigh,vis,dfsvis,adj);
       if(cycledetected)
       {
         return true;
       }
     }
     else if(dfsvis[neigh]){
       //vis
       return true;

     }

   }
   dfsvis[node]=false;
   return false;
}








int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
  for(int i=0;i<edges.size();i++)
  {
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);
  }
  unordered_map<int,bool> vis;
  unordered_map<int,bool> dfsvis;

  for(int i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      bool isCycleFound=checkCycleDFS(i,vis,dfsvis,adj);
      if(isCycleFound)
      return true;
    }
  }
 return false;
}