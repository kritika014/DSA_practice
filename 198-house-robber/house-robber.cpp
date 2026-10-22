class Solution {
public:
    int n;
    int t[105];
    int solve(int i, vector<int>& nums) {
        if (i >= nums.size()) {
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int robbed = nums[i] + solve(i + 2, nums);

        int not_robbed = solve(i + 1, nums);
        return t[i]=max(robbed, not_robbed);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(0, nums);
    }
};