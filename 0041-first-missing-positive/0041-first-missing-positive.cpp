class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Place each number in its correct position if possible
        for (int i = 0; i < n; ++i) {
            // While the current number is a valid positive integer within the range [1, n]
            // AND it is not at its correct index (i.e., nums[i] should be at index nums[i] - 1)
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first index where the number doesn't match the index + 1
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If all numbers 1 to n are present, the answer is n + 1
        return n + 1;
    }
};