class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftArr(n,0);
        vector<int> rightArr(n,0);
        stack<int> s;
        // calculate right smaller
        for (int i = n - 1; i >= 0; i--) {
            while (s.size() > 0 && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            if (s.size() == 0) {
                rightArr[i] = n;
            } else {
                rightArr[i] = s.top();
            }
            s.push(i);
        }
        // calculate left smaller
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() > 0 && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                leftArr[i] = -1;
            } else {
                leftArr[i] = st.top();
            }
            st.push(i);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            int width=rightArr[i]-leftArr[i]-1;
            int currAr=heights[i]*width;
            ans=max(ans,currAr);
        }
        return ans;
    }
};