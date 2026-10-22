class Solution {
public:
    int t[1005][1005];
    int solve(int i, int j,string&text1,string&text2){
        if(text1.length()==0 || text2.length()==0){
            return 0;
        }
        if(i<0||j<0){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(text1[i]==text2[j]){
            return t[i][j]=1+solve(i-1,j-1,text1,text2);
        }
        else{
            return t[i][j]=max(solve(i-1,j,text1,text2),solve(i,j-1,text1,text2));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();
        memset(t,-1,sizeof(t));
        return solve(m-1,n-1,text1,text2);
    }
};