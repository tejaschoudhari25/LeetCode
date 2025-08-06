class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int m = sqrt(n);
        int block = (n + m - 1) / m; // no of blocks
        int ct = 0;
        vector<int> maxB(block); // think of it as a 2-D array and maxof each
                                 // row eg. 0,1,2,3,4,....,m-1 ->1st row

        for (int i = 0; i < n; i++) {
            maxB[i / m] = max(maxB[i / m], baskets[i]);
        }

        for (int f : fruits) {
            int bl; // to keep track of blocks
            int unplaced = 1;//at starting the fruit is not placed
            for (bl = 0; bl < block; bl++) {
                if (maxB[bl] < f) {
                    continue;
                }
                int check = 0;
                maxB[bl] = 0;//now we will again calc the max for particular bock 
                for (int i = 0; i < m; i++) {
                    // to check in a particular block
                    int pos = (bl * m) + i;//position acc to orignal array
                    if (pos < n && baskets[pos] >= f && !check) {
                        baskets[pos] = 0; // used basket
                        check = 1;//and ith type is placed
                    }

                    if(pos<n){
                    maxB[bl]=max(maxB[bl],baskets[pos]);//make new max of the block
                    }
                }
                unplaced =0;//if code does not come upto here this means it is not pplaced 
                        //and unplaced remains 1 
                break;
            }
              ct+=unplaced;//total number of unplaced(unplaced) fruits
        }
        return  ct;
    }
};