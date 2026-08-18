class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> subarray_count;

        // Slide a window of size k across nums
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_in_window;
            for (int j = i; j < i + k; ++j) {
                unique_in_window.insert(nums[j]);
            }

            // Increment window count for each unique element in current
            // subarray
            for (int val : unique_in_window) {
                subarray_count[val]++;
            }
        }

        // Find the largest element that appears in EXACTLY ONE subarray of size
        // k
        int max_val = -1;
        for (auto& [val, count] : subarray_count) {
            if (count == 1) {
                max_val = max(max_val, val);
            }
        }

        return max_val;
    }
};