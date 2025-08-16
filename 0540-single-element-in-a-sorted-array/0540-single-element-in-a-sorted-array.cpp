class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int n = nums.size();
        while(right < n)
        {
            if(nums[left] == nums[right])
            {
                left += 2;
                right += 2;
            }
            else
            {
                break;
                
            }
        }
        return nums[left];
    }
};