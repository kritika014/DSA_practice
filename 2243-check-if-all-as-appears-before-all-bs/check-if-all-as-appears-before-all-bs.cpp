class Solution {
public:
    bool checkString(string s) {
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(j+1<n && s[j]=='b' && s[j+1]=='a'){
                    return false;
                }
            }
        }
        return true;
    }
};