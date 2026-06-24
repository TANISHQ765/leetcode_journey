class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        // Track occupied columns, main diagonals, and anti-diagonals
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false); // For row + col
        vector<bool> diag2(2 * n - 1, false); // For row - col + n - 1
        
        backtrack(0, n, cols, diag1, diag2, count);
        return count;
    }

private:
    void backtrack(int row, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int& count) {
        // Base case: If all queens are successfully placed
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; col++) {
            int d1 = row + col;
            int d2 = row - col + n - 1;

            // Check if the current placement is safe
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue; 
            }

            // Place the queen
            cols[col] = diag1[d1] = diag2[d2] = true;

            // Move to the next row
            backtrack(row + 1, n, cols, diag1, diag2, count);

            // Backtrack (Remove the queen)
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};