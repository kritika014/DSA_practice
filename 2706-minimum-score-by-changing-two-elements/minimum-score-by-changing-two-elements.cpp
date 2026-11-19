class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if (n <= 3) {
            return 0;
        }
        int dropTwoLargest = nums[n - 3] - nums[0];
        int dropTwoSmallest = nums[n - 1] - nums[2];
        int dropOneEach = nums[n - 2] - nums[1];

        int ans=min({dropTwoLargest,dropTwoSmallest,dropOneEach});
        return ans;

    }
};