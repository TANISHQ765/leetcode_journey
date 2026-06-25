class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // Decide whether to add to the current subarray or start fresh from nums[i]
            current_sum = max(nums[i], current_sum + nums[i]);
            
            // Track the highest sum we've seen so far
            max_sum = max(max_sum, current_sum);
        }
        
        return max_sum;
    }
};