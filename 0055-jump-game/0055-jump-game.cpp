class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // If the current index is unreachable, we can't reach the end
            if (i > maxReach) {
                return false;
            }
            
            // Update the furthest reachable index
            maxReach = max(maxReach, i + nums[i]);
            
            // Early exit if we can already reach the last index
            if (maxReach >= n - 1) {
                return true;
            }
        }
        
        return true;
    }
};