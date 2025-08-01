class Solution {
public:
     vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);  

        int posIdx = 0, negIdx = 1; 
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                ans[posIdx] = arr[i];  
                posIdx += 2;           
            } else {
                ans[negIdx] = arr[i];  
                negIdx += 2;           
            }
        }

        return ans;  
    }
};