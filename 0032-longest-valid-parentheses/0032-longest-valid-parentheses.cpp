#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> st;
        st.push(-1); // Base boundary for valid length calculation
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i); // Push index of opening parenthesis
            } else {
                st.pop(); // Pop the matching opening parenthesis or base boundary
                
                if (st.empty()) {
                    // If empty, this current ')' is an unmatched invalid boundary
                    st.push(i); 
                } else {
                    // Calculate length of the current valid substring
                    max_len = std::max(max_len, i - st.top());
                }
            }
        }

        return max_len;
    }
};