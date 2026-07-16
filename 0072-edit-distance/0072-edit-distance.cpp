#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length();
        int n = word2.length();
        
        // dp[i][j] will store the edit distance of word1[0..i-1] and word2[0..j-1]
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        // Base cases: 
        // Converting a string of length i to an empty string requires i deletions
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        // Converting an empty string to a string of length j requires j insertions
        for (int j = 0; j <= n; ++j) {
            dp[0][j] = j;
        }
        
        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    // Characters match, no operation needed
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Take the minimum of Delete, Insert, and Replace operations
                    dp[i][j] = 1 + std::min({
                        dp[i - 1][j],    // Delete
                        dp[i][j - 1],    // Insert
                        dp[i - 1][j - 1] // Replace
                    });
                }
            }
        }
        
        return dp[m][n];
    }
};