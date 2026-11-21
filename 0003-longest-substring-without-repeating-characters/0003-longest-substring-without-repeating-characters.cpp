class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int visited[128] = {0};

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            int index = (unsigned char)s[right];

            while (visited[index] == 1) {
                visited[(unsigned char)s[left]] = 0;
                left++;
            }

            visited[index] = 1;

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};