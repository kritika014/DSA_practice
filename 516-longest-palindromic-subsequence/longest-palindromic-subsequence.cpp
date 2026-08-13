class Solution {
public:
    int t[1005][1005];
    int solve(int i, int j, string&a, string&b) {
        if (a.length() == 0 || b.length() == 0) {
            return 0;
        }
        if (i < 0 || j < 0) {
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if (a[i] == b[j]) {
            return t[i][j]=1+solve(i - 1, j - 1, a, b);
        } else {
            return t[i][j]=max(solve(i - 1, j, a, b), solve(i, j - 1, a, b));
        }
        return 0;
    }
    int longestPalindromeSubseq(string s) {
        string a = s;
        string b = s;
        reverse(b.begin(), b.end());
        memset(t,-1,sizeof(t));
        int n = a.length();
        int m = b.length();
        return solve(n - 1, m - 1, a, b);
    }
};