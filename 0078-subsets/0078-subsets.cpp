class Solution {
public:
    void solve(int index, vector<int>& nums, vector<vector<int>>&ans, vector<int>&current){
        if(index == nums.size()){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        solve(index+1, nums, ans, current);
        current.pop_back();
        solve(index+1, nums, ans, current);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(0, nums, ans, current);
        return ans;
    }
};