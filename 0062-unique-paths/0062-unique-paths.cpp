class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int totalMoves = m + n - 2;
        int k = min(m - 1, n - 1); // Choosing the smaller one to minimize iterations
        
        // Calculate C(totalMoves, k) effectively preventing overflow
        for (int i = 1; i <= k; ++i) {
            ans = ans * (totalMoves - k + i) / i;
        }
        
        return (int)ans;
    }
};