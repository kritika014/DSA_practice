class Solution {
public:
    int t[505][505];
    int solve(int i, int j,string&word1,string&word2){
        if(word1.length()==0|| word2.length()==0){
            return 0;
        }
        if(i<0||j<0){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(word1[i]==word2[j]){
            return t[i][j]=1+solve(i-1,j-1,word1,word2);
        }
        else{
            return t[i][j]=max(solve(i-1,j,word1,word2),solve(i,j-1,word1,word2));
        }
        return 0;
    }
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        int n=word1.length();
        int m=word2.length();
        int lc= solve(n-1,m-1,word1,word2);

        int ans=(n+m)-2*lc;
        return ans;
    }
};