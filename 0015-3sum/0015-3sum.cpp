class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Step 1: Sort the array to use two pointers and easily skip duplicates
        sort(nums.begin(), nums.end());

        // Step 2: Iterate through the array
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate values for the first element to ensure unique triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            // Step 3: Use two pointers to find the remaining two numbers
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second element (left pointer)
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicates for the third element (right pointer)
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers inward after processing a valid triplet
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    // If the sum is too small, move the left pointer to a larger value
                    left++;
                } 
                else {
                    // If the sum is too large, move the right pointer to a smaller value
                    right--;
                }
            }
        }

        return result;
    }
};