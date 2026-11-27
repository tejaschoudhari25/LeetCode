class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& current, vector<int>& candidates, int target, int index){
        if(target == 0){
            ans.push_back(current);
            return;
        }
        if(index >= candidates.size()){
            return;
        }

        if(candidates[index] <= target){
            current.push_back(candidates[index]);
            target -= candidates[index];
            solve(ans, current, candidates, target, index);
            current.pop_back();
            target += candidates[index];
            solve(ans, current, candidates, target, index+1);
        }
        else{
            solve(ans, current, candidates, target, index+1);
        }
        
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(ans, current, candidates, target, 0);
        return ans;

    }
};