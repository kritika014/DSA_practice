class Solution {
public:
    vector<vector<int>> solve(int idx, vector<int>& nums,
                              vector<vector<int>>& ans, vector<int>& temp,
                              int& n) {
        ans.push_back(temp);
        for (int i = idx; i < n; i++) {
            temp.push_back(nums[i]);
            solve(i + 1, nums, ans, temp, n);
            temp.pop_back();
        }
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        return solve(0, nums, ans, temp, n);
    }
};