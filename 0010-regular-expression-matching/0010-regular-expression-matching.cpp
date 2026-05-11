#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(std::string s, std::string p) {
        int m = s.length();
        int n = p.length();
        
        // dp[i][j] will be true if the first i characters in s 
        // match the first j characters in p
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        
        // Base case: empty string matching patterns like "a*", "a*b*", etc.
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // If characters match exactly or pattern has a '.', carry over the previous diagonal state
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // If we encounter a '*', we have two choices
                else if (p[j - 1] == '*') {
                    // Choice 1: The '*' matches zero of the preceding element
                    dp[i][j] = dp[i][j - 2];
                    
                    // Choice 2: The '*' matches one or more of the preceding element
                    // This is only valid if the preceding element matches the current character in s
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};