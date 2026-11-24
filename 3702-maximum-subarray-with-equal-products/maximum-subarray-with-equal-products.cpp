class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        long long maxVal = *max_element(nums.begin(), nums.end());
        long long totalLcm = 1;
        for (int x : nums) {
            totalLcm = lcm(totalLcm, (long long)x);
        }

        long long maxProd =
            (totalLcm <= LLONG_MAX / maxVal) ? totalLcm * maxVal : LLONG_MAX;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {
                long long val = nums[j];
                if (prod > LLONG_MAX / val)
                    break;
                prod *= val;

                g = gcd(g, val);
                l = lcm(l, val);

                if (l <= LLONG_MAX / g && prod == l * g) {
                    ans = max(ans, j - i + 1);
                }

                if (prod > maxProd)
                    break;
            }
        }
        return ans;
    }
};