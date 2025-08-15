class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 1;
        int j = 0;
        int n = arr.size();
        while (k)
        {
            if(j < n)
            {
                if(i == arr[j])
                {
                    i++;
                    j++;
                }
                else 
                {
                    i++;
                    k--;
                }
            }
            else
            {
                i += k;
                break;
            }
        }  
        return i-1;    
    }
};


  