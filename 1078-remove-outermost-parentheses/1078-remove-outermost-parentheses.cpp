class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";

        for( char ch:s){

            if(ch== '('){
                if(!st.empty()){
                    ans.push_back(ch);
                }
                st.push(ch);
            }                            
            else{                       
                if(!(st.empty()) && st.top()=='('){
                    st.pop();
                }
                if(!st.empty()){
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};