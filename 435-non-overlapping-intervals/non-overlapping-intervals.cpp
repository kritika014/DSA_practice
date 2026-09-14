class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int count=0;
        int i=0;
        vector<vector<int>>ans;
        while(i<n){
            int currstart=intervals[i][0];
            int currend=intervals[i][1];
            while(i+1<n && currend>intervals[i+1][0]){
                currend=min(currend,intervals[i+1][1]);
                i++;
            }
            ans.push_back({currstart,currend});
            i++;
        }
        int m=ans.size();
        count=abs(m-n);
        return count;
    }
};