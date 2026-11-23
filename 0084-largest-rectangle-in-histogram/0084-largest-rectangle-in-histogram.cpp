class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int>st;
        int n = heights.size();

        for(int i = 0; i <= n; i++){
            int currentHeight;
            if(i == n){
                currentHeight = 0;
            }
            else{
                currentHeight = heights[i];
            }

            while(!st.empty() && heights[st.top()] >= currentHeight){
                int height = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()){
                    width = i;
                }
                else{
                    width = i - st.top() - 1;
                }
                maxArea = max(maxArea, height*width);
            }
            st.push(i);
        }
        return maxArea;

    }
};