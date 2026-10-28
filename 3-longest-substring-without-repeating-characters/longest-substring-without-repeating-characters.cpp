class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int max_len = 0;
        vector<int> hash_map(128, 0);
        while (j < n) {
            while (j < n && hash_map[s[j]] == 0) {
                hash_map[s[j]]++;
                int len = j - i + 1;
                max_len = max(max_len, len);
                j++;
            }

            if (j < n && hash_map[s[j]] != 0) {
                hash_map[s[i]]--;
                i++;
            }
        }
        return max_len;
    }
};