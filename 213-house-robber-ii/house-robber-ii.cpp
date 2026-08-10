class Solution {
public:
    int t[105][105];
    int solve(int idx,int end,vector<int>& nums,int n){
        if(idx>end){
            return 0;
        }
        if(t[idx][end]!=-1){
            return t[idx][end];
        }
        int take=nums[idx]+solve(idx+2,end,nums,n);
        int not_take=solve(idx+1,end,nums,n);
        return t[idx][end]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        memset(t,-1,sizeof(t));
        return max(solve(0,n-2,nums,n),solve(1,n-1,nums,n));
    }
};