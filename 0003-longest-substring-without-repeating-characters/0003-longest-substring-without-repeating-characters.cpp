class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Map to store the last seen index of each character (initialized to -1)
        vector<int> lastIndex(256, -1);
        
        int maxLength = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            // If the character was seen before AND is within our current window
            if (lastIndex[s[right]] >= left) {
                // Move the left boundary to skip the repeat
                left = lastIndex[s[right]] + 1;
            }
            
            // Record/Update the last seen position of the character
            lastIndex[s[right]] = right;
            
            // Calculate current window size and update max
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};