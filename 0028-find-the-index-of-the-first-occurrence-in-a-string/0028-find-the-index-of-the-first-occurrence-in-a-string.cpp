class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        // If needle is longer than haystack, it can't be a substring
        if (m > n) return -1;
        
        // Loop through haystack until where the needle could still fit
        for (int i = 0; i <= n - m; i++) {
            // Check if the substring starting at i matches needle
            if (haystack.substr(i, m) == needle) {
                return i; // Found the first occurrence
            }
        }
        
        return -1; // Needle not found
    }
};