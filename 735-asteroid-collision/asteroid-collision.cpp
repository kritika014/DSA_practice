class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0 &&
                   st.top() < abs(asteroids[i])) {
                st.pop();
            }
            if (!st.empty() && st.top() > 0 && asteroids[i] < 0 &&
                st.top() == abs(asteroids[i])) {
                st.pop();
            } else if (st.empty() || st.top() < 0 || asteroids[i] > 0) {
                st.push(asteroids[i]);
            }
        }

        ans.resize(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};