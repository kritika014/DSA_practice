class Solution {
public:
    int reverse(int x) {
        bool isnegative = x < 0;
        long long temp = abs((long long )x);
        stack<int> s;
        while (temp > 0) {
            int digit = temp % 10;
            s.push(digit);
            temp = temp / 10;
        }
        long long rev = 0;
        long long place = 1;
        while (!s.empty()) {
            long long ele = s.top();
            s.pop();
            rev = rev + (ele * place);
            place = place * 10;
        }
        if(isnegative){
            rev=-rev;
        }
        if (rev < INT_MIN || rev > INT_MAX)
            return 0;

        return (int)rev;
    }
};