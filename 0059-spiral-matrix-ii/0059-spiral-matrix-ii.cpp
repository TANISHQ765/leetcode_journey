class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // Initialize an n x n matrix with 0s
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        // Define boundaries
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        
        int num = 1; // Starting number
        int target = n * n;
        
        while (num <= target) {
            // 1. Move from Left to Right along the top row
            for (int i = left; i <= right; ++i) {
                matrix[top][i] = num++;
            }
            top++; // Shrink the top boundary
            
            // 2. Move from Top to Bottom along the right column
            for (int i = top; i <= bottom; ++i) {
                matrix[i][right] = num++;
            }
            right--; // Shrink the right boundary
            
            // 3. Move from Right to Left along the bottom row
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--; // Shrink the bottom boundary
            
            // 4. Move from Bottom to Top along the left column
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++; // Shrink the left boundary
        }
        
        return matrix;
    }
};