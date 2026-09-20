class Solution {
public:
    int t[105][105];
    int solve(int i, int j,int m, int n, int&ans){
        if(i>=m||i<0||j>=n || j<0){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(i==m-1 && j==n-1){
            return t[i][j]= 1;
        }
        int down=solve(i+1,j,m,n,ans);
        int right=solve(i,j+1,m,n,ans);
        t[i][j]=down+right;
        return t[i][j];
    }
    int uniquePaths(int m, int n) {
        int ans=0;
        memset(t,-1,sizeof(t));
        return solve(0,0,m,n,ans);
    }
};