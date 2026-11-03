class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        sort(nums.begin(),nums.end());
        int max_ele=nums[n-1];
        for(int i=0;i<n;i++){
            count=count+(max_ele-nums[i]);
        }
        return count;
    }
};