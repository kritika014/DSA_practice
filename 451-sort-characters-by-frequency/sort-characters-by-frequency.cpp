class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mp;
        for (char ch : s) {
            mp[ch]++;
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(),
             [](auto& a, auto& b) { return a.second > b.second; });
        string ans = "";
        for (auto it : v) {
            while (it.second--) {
                ans +=(it.first);
            }
        }
        return ans;
    }
};