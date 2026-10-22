class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int len=0;
        int min_ans=INT_MAX;
        int i=0;
        int sum=0;
        for(int j=0;j<n;j++){
            sum=sum+nums[j];
            while(sum>=target){
                min_ans=min(min_ans,j-i+1);
                sum=sum-nums[i];
                i++;
            }
        }
        return (min_ans==INT_MAX?0:min_ans);
    }
};