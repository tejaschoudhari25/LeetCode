class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& current, vector<int>& candidates, int target, int index){
        if(target == 0){
            ans.push_back(current);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            

            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }

            // if(candidates[i] > target){
            //     break;
            // }

            if(candidates[i] <= target){
                current.push_back(candidates[i]);
                target -= candidates[i];
                solve(ans, current, candidates, target, i+1);
                current.pop_back();
                target += candidates[i];
            }
            else{
                break;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> current;

        solve(ans, current, candidates, target, 0);
        return ans;
    }
};