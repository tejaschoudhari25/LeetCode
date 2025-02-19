class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;  // Stack to store indices of '('
        vector<bool> valid(s.size(), true);  // Track valid characters

        // First pass: Mark invalid parentheses
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);  // Store index of '('
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();  // Valid pair found
                } else {
                    valid[i] = false;  // Unmatched ')'
                }
            }
        }

        // Remove extra unmatched '(' from stack
        while (!st.empty()) {
            valid[st.top()] = false;
            st.pop();
        }

        // Build the result string
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            if (valid[i]) ans += s[i];
        }

        return ans;
    }
};
