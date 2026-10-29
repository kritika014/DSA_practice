class Solution {
public:
    int m;
    int n;
    vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i>=m || j<0||j>=n || grid[i][j]=='0'||grid[i][j]=='$'){
            return;
        }
        grid[i][j]='$';
        for(auto d:dir){
            int new_x=i+d[0];
            int new_y=j+d[1];
            dfs(new_x,new_y,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};