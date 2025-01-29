class Solution {
public:
    vector<vector<int>> result;
    
    void solve(int col, int n, vector<int>& board, vector<bool>& column, vector<bool>& diag1, vector<bool>& diag2) {
        if (col == n) {
            result.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (!column[row] && !diag1[row - col + n - 1] && !diag2[row + col]) {
                // Place the queen
                board[col] = row + 1;
                column[row] = diag1[row - col + n - 1] = diag2[row + col] = true;

                // Move to the next column
                solve(col + 1, n, board, column, diag1, diag2);

                // Backtrack
                column[row] = diag1[row - col + n - 1] = diag2[row + col] = false;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        result.clear();
        vector<int> board(n);  // Stores the row index for each column
        vector<bool> column(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        
        solve(0, n, board, column, diag1, diag2);
        
        return result;
    }
};