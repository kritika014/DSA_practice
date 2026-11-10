class Solution {
public:
    int solve(int i, int n, vector<int>& costs, vector<int>& memo) {
        if (i == n) {
            return 0;
        }
        if (i > n) {
            return 1e9;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        int first =
            (i + 1 <= n) ? costs[i] + 1 + solve(i + 1, n, costs, memo) : 1e9;
        int second = (i + 2 <= n)
                         ? costs[i + 1] + 4 + solve(i + 2, n, costs, memo)
                         : 1e9;
        int third = (i + 3 <= n)
                        ? costs[i + 2] + 9 + solve(i + 3, n, costs, memo)
                        : 1e9;

        return memo[i] = min({first, second, third});
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> memo(n + 1, -1);
        for (int i = n; i >= 0; i--) { // <-- added: warm the memo from the back
            solve(i, n, costs, memo);
        }
        return solve(0, n, costs, memo);
    }
};