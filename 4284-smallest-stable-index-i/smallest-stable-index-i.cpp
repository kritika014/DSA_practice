class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        unordered_map<int,pair<int,int>>mp;
        vector<int>suffix_min(n+1,INT_MAX);
        for(int i=n-1;i>=0;i--){
            suffix_min[i]=min(suffix_min[i+1],nums[i]);

        }
        int max_ele=0;
        for(int i=0;i<n;i++){
            max_ele=max(max_ele,nums[i]);
            if((max_ele-suffix_min[i])<=k){
                return i;
            }
        }

        return -1;
    }
};