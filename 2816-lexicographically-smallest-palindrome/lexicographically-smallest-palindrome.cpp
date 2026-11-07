class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                int min_letter=min(s[i]-'a',s[j]-'a');
                s[i]=min_letter+'a';
                s[j]=min_letter+'a';
            }
            i++;
            j--;
        }
        return s;
    }
};