class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int n=s.length();
        for(int i=1;i<=n;i++){
            char ch=s[i-1];
            int val_ch=26-(ch-'a');

            ans=ans+(i*val_ch);
        }

        return ans;
    }
};