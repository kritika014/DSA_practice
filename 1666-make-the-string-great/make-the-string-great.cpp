class Solution {
public:
    string makeGood(string s) {
        int n=s.length();
        int i=0;
        while(i<n-1){
            if(s[i]!=s[i+1] && tolower(s[i])==tolower(s[i+1])){
                s.erase(i,2);
                n=s.length();

                if(i>0){
                    i--;
                }
            }
            else{
                i++;
            }
        }
        return s;
    }
};