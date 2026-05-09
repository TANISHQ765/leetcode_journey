class Solution {
public:
    bool isPalindrome(int x) {
        // Edge cases: negative numbers and numbers ending in 0 (except 0)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = (reversedHalf * 10) + (x % 10);
            x /= 10;
        }

        // For even digits: x == reversedHalf
        // For odd digits: x == reversedHalf / 10 (removes the middle digit)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};