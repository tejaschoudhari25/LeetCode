class Solution {
public:
    void solve(int index, vector<vector<int>>& ans, vector<int>& current, vector<int>& nums){
        ans.push_back(current);

        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]){
                continue;
            }
            current.push_back(nums[i]);
            solve(i + 1, ans, current, nums);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> current;
        solve(0, ans, current, nums);
        return ans;
    }
};