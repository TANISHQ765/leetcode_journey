#include <climits>
#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        int n = s.length();
        int sign = 1;
        long result = 0; // Use long to detect overflow easily

        // 1. Ignore leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // 2. Check for sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. Conversion and Overflow handling
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow before updating result
            // Max: 2147483647, Min: -2147483648
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return (int)(result * sign);
    }
};