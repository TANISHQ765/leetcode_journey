class Solution {
public:
    int mySqrt(int x) {
        // Base cases for 0 and 1
        if (x == 0 || x == 1) {
            return x;
        }
        
        int start = 1;
        int end = x;
        int ans = 0;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            // Check if mid*mid <= x. 
            // We use division (x / mid) instead of (mid * mid) to prevent integer overflow.
            if (mid <= x / mid) {
                ans = mid;      // mid could be a potential answer
                start = mid + 1; // Try to find a larger value in the right half
            } else {
                end = mid - 1;   // mid is too large, look in the left half
            }
        }
        
        return ans;
    }
};