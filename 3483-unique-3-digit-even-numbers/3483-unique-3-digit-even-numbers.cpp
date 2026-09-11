class Solution {
public:

    int solve(int pos, vector<int>& digits, vector<bool>& used) {

        // 3 digits successfully formed
        if (pos == 3) {
            return 1;
        }

        int count = 0;

        // Avoid duplicate digit choices at this level
        set<int> seen;

        for (int i = 0; i < digits.size(); i++) {

            // This particular copy is already used
            if (used[i])
                continue;

            // Same digit value already tried at this position
            if (seen.count(digits[i]))
                continue;

            // First digit cannot be 0
            if (pos == 0 && digits[i] == 0)
                continue;

            // Last digit must be even
            if (pos == 2 && digits[i] % 2 != 0)
                continue;

            seen.insert(digits[i]);

            // Choose
            used[i] = true;

            // Explore
            count += solve(pos + 1, digits, used);

            // Backtrack
            used[i] = false;
        }

        return count;
    }

    int totalNumbers(vector<int>& digits) {

        vector<bool> used(digits.size(), false);

        return solve(0, digits, used);
    }
};