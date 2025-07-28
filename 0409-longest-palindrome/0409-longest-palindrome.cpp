class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> freq;

        for(auto c : s)
        {
            freq[c]++;
        }
        int length = 0;
        bool oddFound = false;

        for(auto & pair : freq)
        {
            int count = pair.second;

            if(count % 2 == 0)
            {
                length += count; // use all
            }
            else
            {
                length += count - 1;
                oddFound = true;
            }
        }
        if(oddFound) length += 1;
        return length;
    }
};