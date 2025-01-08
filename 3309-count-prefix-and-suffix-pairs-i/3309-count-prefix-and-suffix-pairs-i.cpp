class Solution {
public:
    bool isprefix(string a, string b)
    {
        if(a.size() > b.size())
            return false;

        int left = 0;
        int right = 0;
        while(left < a.size())
        {
            if(a[left] == b[right])
            {
                left++;
                right++;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    bool issuffix(string a, string b)
    {
        if(a.size() > b.size())
            return false;

        int left = a.size()-1;
        int right = b.size()-1;
        while(left >= 0)
        {
            if(a[left] == b[right])
            {
                left--;
                right--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(int i = 0; i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(isprefix(words[i], words[j]) && issuffix(words[i], words[j]))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};