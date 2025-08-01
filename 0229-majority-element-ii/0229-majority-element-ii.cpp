class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i:nums)
        {
            mp[i]++;
        }
        int n = nums.size();
        for(auto it : mp)
        {
            if(it.second > (n/3))
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};