class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n = operations.size();
        for (int i = 0; i < n; i++) {
            if (operations[i] == "C") {
                st.pop();
            } else if (operations[i] == "D") {
                int curr = st.top();
                int newv = curr * 2;
                st.push(newv);
            } else if (operations[i] == "+") {
                int top1 = st.top();
                st.pop();
                int top2 = st.top();

                st.push(top1); // Restore the top element
                st.push(top1 + top2);
            } else {
                st.push(stoi(operations[i]));
            }
        }
        int sum = 0;
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            sum = sum + curr;
        }
        return sum;
    }
};