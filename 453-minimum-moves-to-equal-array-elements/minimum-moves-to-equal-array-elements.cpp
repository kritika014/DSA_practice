class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int min_ele=nums[0];
        for(int i=0;i<n;i++){
            ans=ans+(nums[i]-min_ele);
        }
        return ans;
    }
};