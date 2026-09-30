class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> arr(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] <= n) {
                arr[nums[i]]++;
            }
        }

        int j = 1;

        while (j <= n) {
            if (arr[j] == 0) {
                return j;
            }
            j++;
        }

        return n + 1;
    }
};