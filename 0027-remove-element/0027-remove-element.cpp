class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0; // Pointer to place the next valid element
        
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is not the one we want to remove
            if (nums[i] != val) {
                nums[index] = nums[i];
                index++; // Move the write pointer forward
            }
        }
        
        // 'index' now represents the count of elements not equal to 'val'
        return index;
    }
};