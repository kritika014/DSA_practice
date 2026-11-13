class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        // deque of (prefix-max value, count of positions with that prefix max),
        // front = leftmost segment, back = rightmost segment of the window
        deque<pair<long long, long long>> dq;
        long long sumMax = 0, ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            long long cnt = 1;
            // nums[l] becomes the prefix max for all segments with value <= nums[l]
            while (!dq.empty() && dq.front().first <= nums[l]) {
                cnt += dq.front().second;
                sumMax -= dq.front().first * dq.front().second;
                dq.pop_front();
            }
            dq.push_front({nums[l], cnt});
            sumMax += (long long)nums[l] * cnt;

            // shrink the window from the right until cost <= k
            while (sumMax - (pre[r + 1] - pre[l]) > k) {
                sumMax -= dq.back().first;
                if (--dq.back().second == 0) dq.pop_back();
                r--;
            }
            ans += r - l + 1;
        }
        return ans; 
    }
};