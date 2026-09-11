class Solution {
public:
    bool ispalindrome(string str){
        int i=0;
        int n=str.length();
        int j=n-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int countSubstrings(string s) {
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                string st=s.substr(i,j-i+1);
                if(ispalindrome(st)){
                    ans++;
                }
            }
        }
        return ans;
    }
};