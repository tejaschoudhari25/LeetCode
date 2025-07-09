class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> pge(n);
        int mx = -1;
        for(int i=0; i<n; i++){
            pge[i] = mx;
            mx = max(height[i],mx);
        }
        vector<int> nge(n);
        mx = -1;
        for(int i=n-1; i>=0; i--){
            nge[i] = mx;
            mx = max(height[i],mx);
        }
        int sum = 0;
        for (int i = 1; i < n - 1; i++) {
            int water = min(pge[i], nge[i]) - height[i];
            if (water > 0) sum += water;
        }
        return sum;
    }
};