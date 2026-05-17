#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        // Step 2: Initialize closest_sum with the first triplet
        int closest_sum = nums[0] + nums[1] + nums[2]; 
        
        // Step 3: Iterate through the array
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;
            
            // Step 4: Two-pointer search
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                // Update closest_sum if we found a strictly closer difference
                if (abs(target - current_sum) < abs(target - closest_sum)) {
                    closest_sum = current_sum;
                }
                
                // Move pointers based on how current_sum compares to target
                if (current_sum < target) {
                    left++;
                } else if (current_sum > target) {
                    right--;
                } else {
                    // Exact match found, can't get any closer than a difference of 0
                    return current_sum; 
                }
            }
        }
        
        return closest_sum;
    }
};