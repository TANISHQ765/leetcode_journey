class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<vector<int>>& result) {
        // Base case: If we've considered all positions, we found a valid permutation
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = index; i < nums.size(); i++) {
            // Swap the current element with the element at the 'index' position
            swap(nums[index], nums[i]);
            
            // Recursively generate permutations for the remaining elements
            backtrack(index + 1, nums, result);
            
            // Backtrack: Undo the swap to restore the original array structure
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(0, nums, result);
        return result;
    }
};