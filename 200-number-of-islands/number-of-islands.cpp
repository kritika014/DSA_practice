class Solution {
public:
    int m;
    int n;
    vector<vector<int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int row, int col,vector<vector<char>>& grid){
        grid[row][col]='0';
        for(auto&dir:directions){
            int new_row=row+dir[0];
            int new_col=col+dir[1];

            if(new_row<0 || new_col<0 || new_row>=m || new_col>=n || grid[new_row][new_col]=='0'){
                continue;
            }
            dfs(new_row,new_col,grid);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
         m=grid.size();
         n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};