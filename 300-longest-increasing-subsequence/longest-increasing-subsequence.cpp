class Solution {
public:
    int t[2505][2505];
    int solve(int idx, vector<int>&nums,int prev){
        if(idx>=nums.size()){
            return 0;
        }
        if(prev!=-1 && t[idx][prev]!=-1){
            return t[idx][prev];
        }
        int take=0;
        if(prev==-1||nums[idx]>nums[prev]){
            take=1+solve(idx+1,nums,idx);
        }

        int skip=solve(idx+1,nums,prev);
        if(prev!=-1){
            t[idx][prev]=max(take,skip);
        }
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums,-1);
    }
};