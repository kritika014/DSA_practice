class Solution {
public:
    int m;
    int n;
    int LEFT = 0; ////arrived
    int UP = 1;   // arrived
    int MOD = 1e9 + 7;
    int t[505][505][2];
    int solve(int i, int j, vector<vector<int>>& grid, int camefrom) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if(t[i][j][camefrom]!=-1){
            return t[i][j][camefrom];
        }
        if (grid[i][j] == 1) {
            if (camefrom == LEFT) {
                return t[i][j][camefrom]=solve(i + 1, j, grid, UP);
            } else {
                return t[i][j][camefrom]=solve(i, j + 1, grid, LEFT);
            }
        }
        int count=0;
        count = (count + solve(i + 1, j, grid, UP)) % MOD;
        count = (count + solve(i, j + 1, grid, LEFT)) % MOD;
        return t[i][j][camefrom]=count;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0, 0, grid, LEFT);
    }
};