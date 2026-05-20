#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        
        for (char c : s) {
            // If it's an opening bracket, push to stack
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            // If it's a closing bracket
            else {
                // If stack is empty, there is no matching opening bracket
                if (st.empty()) return false;
                
                char top = st.top();
                // Check if the top elements match the current closing bracket
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '[')) {
                    st.pop(); // Correct match found, remove it
                } else {
                    return false; // Mismatched bracket types
                }
            }
        }
        
        // If the stack is empty, all brackets were matched perfectly
        return st.empty();
    }
};