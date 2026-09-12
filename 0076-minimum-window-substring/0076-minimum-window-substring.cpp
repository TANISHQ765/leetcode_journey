#include <string>
#include <vector>
#include <climits>

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }

        // Frequency map for characters in t
        std::vector<int> target_counts(128, 0);
        for (char c : t) {
            target_counts[c]++;
        }

        int required = 0;
        for (int count : target_counts) {
            if (count > 0) required++;
        }

        // Frequency map for characters in the current window of s
        std::vector<int> window_counts(128, 0);
        
        int left = 0, right = 0;
        int formed = 0; // Number of unique characters meeting target frequency requirement
        
        int min_len = INT_MAX;
        int min_start = 0;

        while (right < s.length()) {
            char char_right = s[right];
            window_counts[char_right]++;

            // Check if frequency of current character matches target frequency in t
            if (target_counts[char_right] > 0 && window_counts[char_right] == target_counts[char_right]) {
                formed++;
            }

            // Try contracting the window from left once a valid window is found
            while (left <= right && formed == required) {
                char char_left = s[left];

                // Update minimum length and start position
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_start = left;
                }

                // Shrink window
                window_counts[char_left]--;
                if (target_counts[char_left] > 0 && window_counts[char_left] < target_counts[char_left]) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return min_len == INT_MAX ? "" : s.substr(min_start, min_len);
    }
};