#include <bits/stdc++.h> 


bool isSafe(int newx, int newy, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n) // Added 'int n' parameter
{
    // Corrected condition: vis[newx][newy] should be !vis[newx][newy]
    if((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && (!vis[newx][newy] && arr[newx][newy] == 1)) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path)
{
    // Base case
    if(x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }

    // Mark the cell as visited
    vis[x][y] = true;

    // 4 movements: down, left, right, up
    // Down
    if(isSafe(x+1, y, vis, arr, n))
    {
        solve(x+1, y, arr, n, ans, vis, path + 'D'); // Corrected: vis+'D' to path+'D'
    }
    // Left
    if(isSafe(x, y-1, vis, arr, n))
    {
        solve(x, y-1, arr, n, ans, vis, path + 'L'); // Corrected: vis+'L' to path+'L'
    }
    // Right
    if(isSafe(x, y+1, vis, arr, n))
    {
        solve(x, y+1, arr, n, ans, vis, path + 'R'); // Corrected: vis+'R' to path+'R'
    }
    // Up
    if(isSafe(x-1, y, vis, arr, n))
    {
        solve(x-1, y, arr, n, ans, vis, path + 'U'); // Corrected: vis+'U' to path+'U'
    }

    // Unmark the cell (backtracking)
    vis[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    if(arr[0][0] == 0)
    {
        return ans;
    }
    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}
