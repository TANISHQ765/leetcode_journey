#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        
        result[0] = findFirstPosition(nums, target);
        result[1] = findLastPosition(nums, target);
        
        return result;
    }

private:
    int findFirstPosition(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int firstIdx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                firstIdx = mid;     // Record the potential answer
                right = mid - 1;    // Keep looking to the left
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return firstIdx;
    }

    int findLastPosition(const vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int lastIdx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                lastIdx = mid;      // Record the potential answer
                left = mid + 1;     // Keep looking to the right
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return lastIdx;
    }
};