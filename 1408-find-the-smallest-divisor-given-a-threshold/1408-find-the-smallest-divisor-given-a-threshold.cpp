class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 1;
        int high = nums[n-1];
        int ans = high;

        while(low <= high)
        {
            int mid = (low+high)/2;
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += (nums[i] + mid - 1)/mid;
            }
            if(sum <= threshold)
            {
                ans = mid;
                high = mid - 1;
            }
            else if(sum > threshold)
            {
                low = mid + 1;
            }
        }
        return ans;

    }
};