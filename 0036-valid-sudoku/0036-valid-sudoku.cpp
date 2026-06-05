class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use arrays of arrays to track seen numbers (1-9)
        // Index 0 will be left unused for simpler 1-9 indexing
        bool rows[9][10] = {false};
        bool cols[9][10] = {false};
        bool boxes[9][10] = {false};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                // Skip empty cells
                if (board[r][c] == '.') {
                    continue;
                }

                // Convert char digit to integer index
                int num = board[r][c] - '0';
                int box_idx = (r / 3) * 3 + (c / 3);

                // Check if the number already exists in the current row, column, or box
                if (rows[r][num] || cols[c][num] || boxes[box_idx][num]) {
                    return false;
                }

                // Mark the number as seen
                rows[r][num] = true;
                cols[c][num] = true;
                boxes[box_idx][num] = true;
            }
        }

        return true;
    }
};