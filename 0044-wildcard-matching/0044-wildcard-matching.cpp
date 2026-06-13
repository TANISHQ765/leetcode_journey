class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        int i = 0, j = 0;
        int starIdx = -1;
        int matchIdx = -1;
        
        while (i < m) {
            // Case 1: Exact match or '?' match. Advance both pointers.
            if (j < n && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            }
            // Case 2: We hit a '*'. Advance pattern pointer, but remember where we saw the '*' 
            // and where we currently are in the string.
            else if (j < n && p[j] == '*') {
                starIdx = j;
                matchIdx = i;
                j++;
            }
            // Case 3: Characters don't match, but we have seen a '*' previously.
            // We assume the '*' matched one more character from 's'. 
            // Backtrack 'j' to just after the '*' and advance 'i' from our last match index.
            else if (starIdx != -1) {
                j = starIdx + 1;
                matchIdx++;
                i = matchIdx;
            }
            // Case 4: Characters don't match and no '*' was seen to save us.
            else {
                return false;
            }
        }
        
        // After fully traversing 's', any remaining characters in 'p' MUST be '*' to be a valid match.
        while (j < n && p[j] == '*') {
            j++;
        }
        
        return j == n;
    }
};