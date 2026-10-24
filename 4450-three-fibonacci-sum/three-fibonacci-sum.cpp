class Solution {
public:
    bool threeFibonacciSum(int n) {
        vector<long long> fib = {0, 1};
        while (true) {
            long long next = fib[fib.size() - 1] + fib[fib.size() - 2];
            if (next > n)
                break;
            fib.push_back(next);
        }

        // Step 2: 3Sum-style search
        int size = fib.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                for (int k = j + 1; k < size; k++) {
                    // the problem needs CONSECUTIVE terms
                    if (j == i + 1 && k == j + 1 &&
                        fib[i] + fib[j] + fib[k] == n) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};