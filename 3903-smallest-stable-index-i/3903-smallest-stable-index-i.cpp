class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int max = INT_MIN;
        int smallest = INT_MAX;
        for(int i = 0; i < n; ++i){
            max = std::max(max,nums[i]);
            int min = nums[i];
            for(int j = i+1; j < n; ++j){
                min = std::min(min, nums[j]);
            }
            if(max - min <= k){
                smallest = std::min(smallest, i);
            }
        }
        if(smallest == INT_MAX) return -1;
        return smallest;
    }
};