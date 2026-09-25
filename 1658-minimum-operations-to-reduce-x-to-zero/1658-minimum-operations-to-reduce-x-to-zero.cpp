class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        int find = sum - x;

        if(find == 0)
            return nums.size();

        int start = 0;
        int end = 0;
        int currSum = 0;
        int maxLen = -1;

        while(end < nums.size()) {
            currSum += nums[end];

            while(currSum > find && start <= end) {
                currSum -= nums[start];
                start++;
            }

            if(currSum == find) {
                maxLen = max(maxLen, end - start + 1);
            }

            end++;
        }

        if(maxLen == -1)
            return -1;

        return nums.size() - maxLen;
    }
};