class Solution {
public:
    int find(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            if (nums[i] > nums[i + 1]) {
                return i;
            }
        }
        return 0;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = find(nums);
        int i = 0;
        int j = pivot ;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        // 2nd half
        i = pivot + 1;
        j = n - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        return -1;
    }
};