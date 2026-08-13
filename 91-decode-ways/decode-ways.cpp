class Solution {
public:
    int t[105];
    int solve(int idx,string&s,int&n ){
        if(idx==n){
            return 1;
        }
        if(s[idx]=='0'){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        int take_one=solve(idx+1,s,n);
        int take_two=0;
        if(idx+1<n){
            if(s[idx]=='1'|| s[idx]=='2' && s[idx+1]<='6'){
                take_two=solve(idx+2,s,n);
            }
        }
        return t[idx]=(take_one+take_two);
    }
    int numDecodings(string s) {
        int n=s.size();
        memset(t,-1,sizeof(t));
        return solve(0,s,n);
    }
};