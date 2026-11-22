class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int freq[26] = {0};
        int maxFreq = 0;
        int maxLength = 0;

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'A']++;
            maxFreq = max(maxFreq, freq[s[i] - 'A']);

            while((i - left + 1) - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, i - left + 1);
        }
        return maxLength;
    }
};