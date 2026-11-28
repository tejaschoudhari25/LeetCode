class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& current, int n, int k, int start){
        if(current.size() == k){
            ans.push_back(current);
            return;
        }
        for(int i = start; i <= n; i++){
            current.push_back(i);
            solve(ans, current, n, k, i+1);
            current.pop_back();
            
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(ans, current, n, k, 1);
        return ans;
    }
};