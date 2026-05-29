class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: 32-bit signed integer overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Determine the sign of the result
        // True if the signs are different, meaning the result will be negative
        bool isNegative = (dividend < 0) ^ (divisor < 0);
        
        // Use long long to prevent absolute value overflow issues with INT_MIN
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);
        
        long long quotient = 0;
        
        // Perform the bit-shifting division logic
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;
            
            // Shift left until tempDivisor * 2 exceeds absDividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }
            
            // Subtract the largest found multiple from dividend
            absDividend -= tempDivisor;
            // Add the corresponding multiple to the quotient
            quotient += multiple;
        }
        
        // Apply the sign and return
        return isNegative ? -quotient : quotient;
    }
};