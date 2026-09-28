class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int>hash(26,0);
        int n=s.length();
        char ans='\0';
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
            if(hash[s[i]-'a']==2){
                ans=s[i];
                break;
            }
        }
        return ans;
    }
};