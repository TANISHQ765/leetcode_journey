class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_water = 0;

        while (left < right) {
            // Calculate current area
            int h = min(height[left], height[right]);
            int w = right - left;
            int current_area = h * w;

            // Update maximum area found so far
            max_water = max(max_water, current_area);

            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};