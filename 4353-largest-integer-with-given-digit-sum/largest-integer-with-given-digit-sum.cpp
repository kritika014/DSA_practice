class Solution {
public:
    bool isSum(int curr, int num) {
        int sum = 0;
        while (curr > 0) {
            int dig = curr % 10;
            sum = sum + dig;
            curr = curr / 10;
        }
        return (sum == num);
    }
    int largestInteger(int n, int s) {
        int ans = -1;
        int lower_limit = pow(10, n - 1);
        int upper_limit = pow(10, n) - 1;

        if (s == 0) {
            return 0;
        }
        for (int i = lower_limit; i <= upper_limit; i++) {
            int curr = i;
            if (isSum(curr, s)) {
                ans = max(ans, i);
            }
        }
        return ans;
    }
};