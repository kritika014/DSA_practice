class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int max_len = 1;
        int len = 1;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && nums[i + 1] == nums[i]) {
                continue;
            }
            if (i + 1 < n && nums[i + 1] - nums[i] == 1) {
                len++;
            } else {
                max_len = max(max_len, len);
                len = 1;
            }
        }
        return max_len;
    }
};