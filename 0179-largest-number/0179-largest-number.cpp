class Solution {
public:
    static bool comparator(int x, int y) {
        string a = to_string(x);
        string b = to_string(y);

        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comparator);

        string ans = "";

        for(int num : nums) {
            ans += to_string(num);
        }

        if(ans[0] == '0')
            return "0";

        return ans;
    }
};