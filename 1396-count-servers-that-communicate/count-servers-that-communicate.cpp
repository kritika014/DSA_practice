class Solution {
public:
    int m;
    int n;
    int count_connection(int r,int c,vector<vector<int>>& grid){
        if(r<0||r>=m||c<0||c>=n||grid[r][c]==0){
            return 0;
        }
        int row_count=0;
        int col_count=0;
        for(int k=0;k<m;k++){
            if(grid[k][c]==1){
                col_count++;
            }
        }
        for(int k=0;k<n;k++){
            if(grid[r][k]==1){
                row_count++;
            }
        }

        if(row_count>1||col_count>1){
            return 1;
        }
        return 0;
    }
    int countServers(vector<vector<int>>& grid) {
        m=grid.size();
         n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   ans=ans+count_connection(i,j,grid);
                }
            }
        }

        return ans;
    }
};