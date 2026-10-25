class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int total_staircases = 0;
        
        for (int i = 0; i < n; ++i) {
            vector<int> distinct_values;
            unordered_map<int, int> freq;
            
            for (int j = i; j < n; ++j) {
                int val = nums[j];
                if (freq[val] == 0) {
                    distinct_values.push_back(val);
                }
                freq[val]++;
                
                bool valid = true;
                int k = distinct_values.size();
                for (int idx = 0; idx < k; ++idx) {
                    if (freq[distinct_values[idx]] != idx + 1) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    total_staircases++;
                }
            }
        }
        
        return total_staircases;
        
    }
};