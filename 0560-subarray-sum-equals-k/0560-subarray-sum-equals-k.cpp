class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int count = 0;

        mp[0] = 1;
        int currentSum = 0;

        for(int i = 0; i < nums.size(); i++){
            currentSum += nums[i];
            int required = currentSum - k;

            if(mp.find(required) != mp.end()){
                count += mp[required];
            }
            mp[currentSum]++;
        }
        return count;
    }
};