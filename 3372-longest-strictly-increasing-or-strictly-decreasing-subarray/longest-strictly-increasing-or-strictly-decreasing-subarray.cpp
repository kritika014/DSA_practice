class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int max_len = 1;
        while (j + 1 < n) {
            if (nums[j+1]> nums[j]) {
                i = j; // Window ka start point set kiya
                while (j + 1 < n && nums[j + 1] > nums[j]) {
                    j++;
                }
                max_len = max(max_len, j - i + 1);
            }
            else if (nums[j+1]<nums[j]) {
                i = j; // Window ka start point set kiya
                while (j + 1 < n && nums[j + 1] < nums[j]) {
                    j++;
                }
                max_len = max(max_len, j - i + 1);
            }
            else{
                j++;
            }
        }

        return max_len;
    }
};