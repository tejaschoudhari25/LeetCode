class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high) 
        {
            int mid = (low + high) / 2;
            long long ans = 0; 
            for(int i = 0; i < piles.size(); i++) 
            {
                ans += (piles[i] + mid - 1) / mid;  
            }

            if(ans <= h) 
            {
                high = mid;   
            } 
            else 
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
