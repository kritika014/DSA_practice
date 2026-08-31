class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(j-i+1>k){
            if(abs(x-arr[i])>abs((x-arr[j]))){
                i++;
            }
            else{
                j--;
            }
        }
        return vector<int>(arr.begin() + i, arr.begin() + j + 1); 
    }
};