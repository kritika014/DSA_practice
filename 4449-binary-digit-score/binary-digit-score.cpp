class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < 32; i++) {
            if (((a >> i) & 1) == 1){
                s1++;
            }
        }
        for (int i = 0; i < 32; i++) {
            if (((b >> i) & 1)==1){
                s2++;
            }
        }
        int ans=0;
        if(s1>=s2){
            ans= s1*s2;
        }
        else{
            ans=s2/s1;
        }
        return ans;
    }
};