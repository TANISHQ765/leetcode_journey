class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: If the array is empty, return 0
        if (nums.empty()) return 0;
        
        int i = 0; // Slow pointer for the last unique element
        
        // Fast pointer 'j' explores the rest of the array
        for (int j = 1; j < nums.size(); j++) {
            // If we find a new unique element
            if (nums[j] != nums[i]) {
                i++;             // Move unique element boundary forward
                nums[i] = nums[j]; // Update the next unique position
            }
        }
        
        // The number of unique elements is the index 'i' + 1
        return i + 1;
    }
};