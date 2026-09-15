class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> temp(n, vector<int>(n, 0));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int num = 1;
        while (top <= bottom && left <= right) {
            for (int col = left; col <= right; col++) {
                temp[top][col] = num++;
            }
            top++;
            for (int row = top; row <= bottom; row++) {
                temp[row][right] = num++;
            }
            right--;
            for (int col = right; col >= left; col--) {
                temp[bottom][col] = num++;
            }
            bottom--;

            for(int row=bottom;row>=top;row--){
                temp[row][left]=num++;
            }
            left++;
        }

        return temp;
    }
};