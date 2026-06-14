class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int current_end = 0;
        int farthest = 0;
        
        // We stop at nums.size() - 1 because we don't need to jump from the last element
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the farthest index we can reach from the current position
            farthest = max(farthest, i + nums[i]);
            
            // If we have reached the end of the range for the current jump
            if (i == current_end) {
                jumps++;
                current_end = farthest;
                
                // If the current end is already at or beyond the last index, we can stop
                if (current_end >= nums.size() - 1) {
                    break;
                }
            }
        }
        
        return jumps;
    }
};