class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // Find an empty cell
                if (board[i][j] == '.') {
                    // Try placing numbers from '1' to '9'
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // Tentatively place the character
                            
                            // Recursively try to solve the rest of the board
                            if (solve(board)) {
                                return true; 
                            }
                            
                            board[i][j] = '.'; // Backtrack if it doesn't lead to a solution
                        }
                    }
                    return false; // If no number fits, this path is invalid
                }
            }
        }
        return true; // Entire board is successfully filled
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row constraint
            if (board[row][i] == c) return false;
            
            // Check column constraint
            if (board[i][col] == c) return false;
            
            // Check 3x3 sub-grid constraint
            // (row / 3) * 3 finds the starting row of the 3x3 box
            // (col / 3) * 3 finds the starting column of the 3x3 box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }
};