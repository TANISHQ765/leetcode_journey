class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        int start = 0, maxLen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Check for odd length palindromes (center is s[i])
            int len1 = expandAroundCenter(s, i, i);
            // Check for even length palindromes (center is between s[i] and s[i+1])
            int len2 = expandAroundCenter(s, i, i + 1);
            
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                // Calculate the new start index based on the center i and length len
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }

private:
    int expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Returns the length of the palindrome found
        return right - left - 1;
    }
};