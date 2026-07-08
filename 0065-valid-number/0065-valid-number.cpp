class Solution {
public:
    bool isNumber(string s) {
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExponent = false;
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            
            if (isdigit(ch)) {
                seenDigit = true;
            } 
            else if (ch == '+' || ch == '-') {
                // A sign is only valid at index 0 or right after an exponent 'e'/'E'
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } 
            else if (ch == '.') {
                // A dot is invalid if we have already seen a dot or an exponent
                if (seenDot || seenExponent) {
                    return false;
                }
                seenDot = true;
            } 
            else if (ch == 'e' || ch == 'E') {
                // An exponent is invalid if we've already seen one, or if no digit preceded it
                if (seenExponent || !seenDigit) {
                    return false;
                }
                seenExponent = true;
                seenDigit = false; // Reset to ensure it's followed by a valid integer
            } 
            else {
                // Any other character (like letters, spaces) is invalid
                return false;
            }
        }
        
        // The string is valid only if it ends having successfully processed a trailing digit
        return seenDigit;
    }
};