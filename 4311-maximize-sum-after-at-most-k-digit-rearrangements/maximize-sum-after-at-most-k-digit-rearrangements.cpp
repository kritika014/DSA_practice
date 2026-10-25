class Solution {
public:
    int solve(int num, vector<int>& ele) {
        while (num > 0) {
            int digit = num % 10;
            ele.push_back(digit);
            num = num / 10;
        }
        sort(ele.begin(), ele.end(), greater<int>());
        int new_num = 0;
        for (int d : ele) {
            new_num = new_num * 10 + d;
        }
        return new_num;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> new_arr = nums;
        vector<long long> gains;
        long long sum=0;
        for (int i = n - 1; i >= 0; i--) {
            int first_victim = nums[i];
            sum=sum+first_victim;
            vector<int> ele;
            int new_first = solve(first_victim, ele);
            if (first_victim < new_first) {
                gains.push_back(new_first - first_victim);
            }
        }
        sort(gains.begin(), gains.end(), greater<long long>());
        for (int i = 0; i < (int)gains.size() && i < k; i++) {
            sum += gains[i];
        }
        return sum;
    }
};