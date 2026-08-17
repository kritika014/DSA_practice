class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        for(auto it:mp){
            if(it.second>=2){
                return it.first;
                break;
            }
        }
        return 0;
    }
};