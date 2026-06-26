class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        
        // Initialize the boundaries
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while (top <= bottom && left <= right) {
            // 1. Move Right across the top row
            for (int j = left; j <= right; ++j) {
                result.push_back(matrix[top][j]);
            }
            top++; // Move the top boundary down
            
            // 2. Move Down along the right column
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
            }
            right--; // Move the right boundary left
            
            // 3. Move Left across the bottom row (if rows remain)
            if (top <= bottom) {
                for (int j = right; j >= left; --j) {
                    result.push_back(matrix[bottom][j]);
                }
                bottom--; // Move the bottom boundary up
            }
            
            // 4. Move Up along the left column (if columns remain)
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    result.push_back(matrix[i][left]);
                }
                left++; // Move the left boundary right
            }
        }
        
        return result;
    }
};