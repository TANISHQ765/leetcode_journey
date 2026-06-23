class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        // Sets to keep track of columns and diagonals already under attack
        unordered_set<int> cols;
        unordered_set<int> diag1; // (row - col) is constant for major diagonals
        unordered_set<int> diag2; // (row + col) is constant for minor diagonals
        
        backtrack(0, n, board, ans, cols, diag1, diag2);
        return ans;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& ans,
                   unordered_set<int>& cols, unordered_set<int>& diag1, unordered_set<int>& diag2) {
        // Base case: If we've successfully placed queens in all rows, add the configuration to answers
        if (row == n) {
            ans.push_back(board);
            return;
        }
        
        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; ++col) {
            int d1 = row - col;
            int d2 = row + col;
            
            // Check if the current column or diagonals are under attack
            if (cols.count(col) || diag1.count(d1) || diag2.count(d2)) {
                continue; 
            }
            
            // Place the queen (Make choice)
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(d1);
            diag2.insert(d2);
            
            // Move to the next row (Recurse)
            backtrack(row + 1, n, board, ans, cols, diag1, diag2);
            
            // Remove the queen (Backtrack)
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(d1);
            diag2.erase(d2);
        }
    }
};