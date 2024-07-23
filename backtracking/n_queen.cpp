#include <bits/stdc++.h>

bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
    int x = row;
    int y = col;

    // Check same row
    while (y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
    }

    x = row;
    y = col;
    // Check upper diagonal
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;
    // Check lower diagonal
    while (x < n && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }

    return true;
}

void addSol(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
    // Base case all queens are placed
    if (col == n) {
        addSol(ans, board, n);
        return;
    }

    // Try placing queen in all rows one by one
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            // Place the queen
            board[row][col] = 1;
            //rec
            solve(col + 1, ans, board, n);
            //backtrk
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    solve(0, ans, board, n);
    return ans;
}

