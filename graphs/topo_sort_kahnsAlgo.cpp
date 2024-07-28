vector<int> topologicalSort(vector<vector<int>> & edges, int v,  int e)
{
    //create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0;i<e;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
    }
    //find all indegree
    vector<int> indegree(v);
    for(auto i:adj)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }
    //0 indeg push
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
        //do bfs
        vector<int> ans;
        while(!q.empty())
        {
            int front=q.front();
            q.pop();
            //ans store
            ans.push_back(front);
            //neigh indeg update
            for(auto neigh:adj[front])
            {
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    q.push(neigh);
                }
            }
        }
    }
    return ans;
}