class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int val=n/2;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count>=val){
                return nums[i];
            }
        }
        return 0;
    }
};