class Solution {
public:
    vector<vector<int>> directions = {{0, -1}, {-1, -1}, {1, -1}};
    bool isSafe(int row, int col, vector<string>& board, int n) {
        for (auto& dir : directions) {
            int new_row = row + dir[0];
            int new_col = col + dir[1];

            // Use a while loop to scan all the way to the edge of the board
            while (new_row >= 0 && new_row < n && new_col >= 0 && new_col < n) {
                if (board[new_row][new_col] == 'Q') {
                    return false;
                }
                new_row += dir[0];
                new_col += dir[1];
            }
        }
        return true;
    }
    void solve(int col, vector<string>& board, int count,
               vector<vector<string>>& ans, int& n) {
        if (count == n) {
            ans.push_back(board);
            return;
        }
        vector<string> path;
        for (int i = 0; i < n; i++) {
            if (isSafe(i, col, board, n)) {
                board[i][col] = 'Q';
                solve(col + 1, board, count + 1, ans, n);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        int count = 0;
        // vector<vector<string>>maze(n,vector<string>(n,'.'));
        vector<string> board(n, string(n, '.'));
        int col = 0;
        solve(col, board, count, ans, n);
        return ans;
    }
};