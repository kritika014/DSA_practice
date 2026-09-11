class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (st.empty() || ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            if (ch == ')') {
                if (st.top() != '(') {
                    return false;
                } else {
                    st.pop();
                }
            } else if (ch == '}') {
                if (st.top() != '{') {
                    return false;
                } else {
                    st.pop();
                }
            } 
            else if (ch == ']') {
                if (st.top() != '[') {
                    return false;
                } else {
                    st.pop();
                }
            }
        }

        return st.empty();
    }
};