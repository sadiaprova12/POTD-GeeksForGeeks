class Solution {
  public:
    // Function to check if placing 'num' at mat[row][col] is valid
    bool isValid(vector<vector<int>> &mat, int row, int col, int num) {
        // Check row & column
        for (int i = 0; i < 9; i++) {
            if (mat[row][i] == num || mat[i][col] == num)
                return false;
        }

        // Check 3x3 subgrid
        int startRow = (row / 3) * 3, startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[startRow + i][startCol + j] == num)
                    return false;
            }
        }

        return true;
    }

    // Backtracking function to solve Sudoku
    bool solve(vector<vector<int>> &mat) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (mat[row][col] == 0) {  // Empty cell found
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(mat, row, col, num)) {  
                            mat[row][col] = num;  // Place number

                            if (solve(mat))  // Recur for next empty cell
                                return true;

                            mat[row][col] = 0;  // Backtrack
                        }
                    }
                    return false;  // No number fits, backtrack
                }
            }
        }
        return true;  // Solution found
    }

    // Wrapper function to solve Sudoku
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
};