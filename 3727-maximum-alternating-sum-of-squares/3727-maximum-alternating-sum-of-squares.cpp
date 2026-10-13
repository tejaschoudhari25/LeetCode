class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> sq;

        for (int x : nums) {
            sq.push_back(1LL * x * x);
        }

        sort(sq.begin(), sq.end());

        int left = 0;
        int right = sq.size() - 1;
        long long ans = 0;

        while (right > left) {
            ans += sq[right];
            ans -= sq[left];
            right--;
            left++;
        }

        if (left == right) {
            ans += sq[left];
        }

        return ans;
    }
};