class Solution {
public:
    bool checkDivisibility(int n) {
        int digsum=0;
        int digprod=1;
        int temp=n;
        while(temp>0){
            int digit=temp%10;
            digsum=digsum+digit;
            digprod=digprod*digit;
            temp=temp/10;
        }

        int total=digsum+digprod;
        if(n%total==0){
            return true;
        }
        return false;
    }
};