class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=INT_MIN;
        int i=0;
        int j=n-1;
        while(i<j){
            int h=min(height[i],height[j]);
            int l=j-i;
            int area=h*l;
            ans=max(ans,area);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};