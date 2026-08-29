class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string ans = "";
        int i = 0;
        int j = 0;
        bool turn1 = true;
        while (i < n && j < m) {
            if (turn1) {
                ans = ans + word1[i];
                turn1=false;
                i++;
            }
            else{
                ans = ans + word2[j];
                turn1=true;
                j++;
            }
        }
        while(i<n){
            ans=ans+word1[i];
            i++;
        }
        while(j<m){
            ans=ans+word2[j];
            j++;
        }
        return ans;
    }
};