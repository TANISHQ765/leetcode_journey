#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals based on the start times
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> merged;
        
        // Step 2: Iterate through the sorted intervals
        for (const auto& interval : intervals) {
            // If merged is empty or no overlap exists
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } 
            // If overlap exists, merge by updating the end time
            else {
                merged.back()[1] = std::max(merged.back()[1], interval[1]);
            }
        }

        return merged;
    }
};