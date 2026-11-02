class Solution {
public:
    int n;
    int minMoves2(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=n/2;
        int mid_ele=nums[mid];
        int count=0;
        for(int i=0;i<n;i++){
            count=count+abs(mid_ele-nums[i]);
        }
        return count;
    }
};