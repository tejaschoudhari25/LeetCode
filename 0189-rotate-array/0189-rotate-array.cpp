class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  

        deque<int> dq;

        for (int i = n - k; i < n; i++) {
            dq.push_back(nums[i]);
        }

        for (int i = 0; i < n - k; i++) {
            dq.push_back(nums[i]);
        }

        for (int i = 0; i < n; i++) {
            nums[i] = dq[i];
        }
    }
};
