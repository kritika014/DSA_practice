class Solution {
public:
    int t[1001][1001];
    bool solve(string&s, int i, int j){
        if(i>=j){
            return 1;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(s[i]==s[j]){
            return t[i][j]=solve(s,i+1,j-1);
        }
        return 0;
    }
    string longestPalindrome(string s) {
        memset(t,-1,sizeof(t));
        int n=s.length();
        int max_len=INT_MIN;
        int sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)){
                    int len=j-i+1;
                    if(len>max_len){
                        max_len=len;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,max_len);
    }
};