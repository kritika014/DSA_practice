class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        vector<char> temp(n,0);
        for (int i = 0; i < n; i++) {
            temp[i] = s[n - i - 1];
        }
        s = temp;
    }
};