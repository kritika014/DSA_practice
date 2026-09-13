class Solution {
public:
    int daysNeeded(vector<int>& weights, int capacity) {
        int total = 0;
        int count = 1;
        for (int w : weights) {
            if (total + w > capacity) {
                count++;
                total = 0;
            }
            total += w;
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (daysNeeded(weights, mid) <= days) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};