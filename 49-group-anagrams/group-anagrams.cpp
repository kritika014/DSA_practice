class Solution {
public:
    string generate(string &wrd){
        vector<int>chars(26,0);
        for(char ch:wrd){
            chars[ch-'a']++;
        }
        string ans="";
        for(int i=0;i<26;i++){
            if(chars[i]>0){
                ans=ans+string(chars[i],i+'a');
            }
        }
        return ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
            string word=strs[i];
            string new_word=generate(word);
            mp[new_word].push_back(word);
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};