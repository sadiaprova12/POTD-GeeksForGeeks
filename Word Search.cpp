class Solution {
  public:
    int n, m;
    
    // Check if the cell is within bounds and matches the current character in the word
    bool isValid(int i, int j, int index, vector<vector<char>>& mat, string& word) {
        return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == word[index]);
    }

    // DFS function to explore possible paths
    bool dfs(int i, int j, int index, vector<vector<char>>& mat, string& word) {
        if (index == word.size()) return true; // Word completely found

        if (!isValid(i, j, index, mat, word)) return false;

        char temp = mat[i][j]; // Store character
        mat[i][j] = '#'; // Mark as visited

        // Explore 4 directions: up, down, left, right
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int newX = i + dx[d], newY = j + dy[d];
            if (dfs(newX, newY, index + 1, mat, word)) {
                return true;
            }
        }

        mat[i][j] = temp; // Restore original character (Backtrack)
        return false;
    }

    // Function to check if the word exists in the matrix
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        n = mat.size();
        m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == word[0]) { // Start DFS from first character match
                    if (dfs(i, j, 0, mat, word)) return true;
                }
            }
        }
        return false;
    }
};