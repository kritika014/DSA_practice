class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;
        int len = INT_MIN;
        if(n==0){
            return 0;
        }
        while (j < n) {
            mp[s[j]]++;
            while(mp[s[j]]>1) {
                mp[s[i]]--;
                i++;
            }
            int temp_len=j-i+1;
            len=max(len,temp_len);
            j++;
        }
        return len;
    }
};