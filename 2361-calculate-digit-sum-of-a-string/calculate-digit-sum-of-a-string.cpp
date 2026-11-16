class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next_s = "";

            // Traverse the string in steps of k to form groups
            for (size_t i = 0; i < s.length(); i += k) {
                int group_sum = 0;
                size_t end = min(s.length(), i + k);

                // Sum the digits of the current group
                for (size_t j = i; j < end; ++j) {
                    group_sum += s[j] - '0';
                }

                // Append the sum as a string to the next round's string
                next_s += to_string(group_sum);
            }

            // Update s with the newly formed string
            s = next_s;
        }

        return s;
    }
};