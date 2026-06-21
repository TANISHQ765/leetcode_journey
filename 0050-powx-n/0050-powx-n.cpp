class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n; // Use long long to prevent overflow when n = -2^31
        
        // Handle negative power
        if (nn < 0) {
            x = 1.0 / x;
            nn = -nn;
        }
        
        double ans = 1.0;
        while (nn > 0) {
            // If the power is odd, multiply the current base to the answer
            if (nn % 2 == 1) {
                ans *= x;
            }
            // Square the base and halve the power
            x *= x;
            nn /= 2;
        }
        
        return ans;
    }
};