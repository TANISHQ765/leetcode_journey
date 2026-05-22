class Solution {
public:
    void backtrack(vector<string>& result, string current_string, int open, int close, int n) {
        // Base case: if the current string reached the maximum length required (2 * n)
        if (current_string.length() == 2 * n) {
            result.push_back(current_string);
            return;
        }
        
        // Rule 1: We can always add an open parenthesis if we haven't used all n of them
        if (open < n) {
            backtrack(result, current_string + "(", open + 1, close, n);
        }
        
        // Rule 2: We can only add a close parenthesis if it won't exceed the current open ones
        if (close < open) {
            backtrack(result, current_string + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};