class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        // sort(nums.begin(), nums.end());
        int i = 0;
        while (i < n) {
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                i++;
            }

            // Store the unique element (or the last copy of a duplicate group)
            temp.push_back(nums[i]);

            // Move to the start of the next element
            i++;
        }
        nums = temp;
        return temp.size();
    }
};