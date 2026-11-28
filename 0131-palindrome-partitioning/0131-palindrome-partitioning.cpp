class Solution {
public:
    bool isPalindrome(string s){
        int left = 0;
        int right = s.size()-1;

        while(left < right){
            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& current, string s, int index){
        if(index == s.size()){
            ans.push_back(current);
            return;
        }

        for(int i = index; i < s.size(); i++){
            string temp = s.substr(index, i-index+1);

            if(isPalindrome(temp)){
                current.push_back(temp);
                solve(ans, current, s, i+1);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        solve(ans, current, s, 0);
        return ans;
    }
};