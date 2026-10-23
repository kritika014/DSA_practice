class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>leftSmaller(n,0);
        vector<int>rightSmaller(n,0);
        stack<int>st;
        int area=0;
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()==0){
                rightSmaller[i]=n;
            }
            else{
                rightSmaller[i]=st.top();
            }
            st.push(i);
        }
        stack<int>s;
        for(int i=0;i<n;i++){
             while(s.size()>0 && heights[s.top()]>=heights[i]){
                s.pop();
            }
            if(s.size()==0){
                leftSmaller[i]=-1;
            }
            else{
                leftSmaller[i]=s.top();
            }
            s.push(i);
        }

        for(int i=0;i<n;i++){
            int width=rightSmaller[i]-leftSmaller[i]-1;
            int currAr=heights[i]*width;
            area=max(area,currAr);
        }
        return area;
    }
};