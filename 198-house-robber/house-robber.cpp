class Solution {
public:
    int t[105];
    int solve(int idx,vector<int>& nums,int&n){
        if(idx>=n){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        int take=nums[idx]+solve(idx+2,nums,n);
        int not_take=solve(idx+1,nums,n);
        return t[idx]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
      int n=nums.size();
      memset(t,-1,sizeof(t));
      return solve(0,nums,n);  
    }
};