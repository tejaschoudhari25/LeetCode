class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int prevSmall = INT_MIN;
        int largest = 1;
        int cnt = 0;

        if(nums.size() == 0)
        {
            return 0;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i]-1 == prevSmall)
            {
                cnt++;
                prevSmall = nums[i];
            }
            else if(nums[i] != prevSmall)
            {
                cnt = 1;
                prevSmall = nums[i];
            }
            largest = max(largest, cnt);
        }
        return largest;
    }
};

// 1 2 3 4 100 200