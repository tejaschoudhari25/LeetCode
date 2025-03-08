class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int operations = INT_MAX;
        for (int i = 0; i < blocks.size() - k + 1; i++)
        {
            int black = 0;
            for (int j = i; j < i+k; j++)
            {
                if(blocks[j] == 'B')
                {
                    black++;
                }
            }
            if(black == k)
            {
                return 0;
            }
            else
            {
                int diff = abs(black - k);
                operations  = min(operations, diff);
            }
        }

        return operations;
    }
};