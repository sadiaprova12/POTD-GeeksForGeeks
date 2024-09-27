class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n = arr.size();
        std::vector<int> dp(n, INT_MAX);  // Initialize dp array with a large value
        dp[0] = 0;  // Starting point, no cost to stand on the first stone

        // Loop over each stone
        for (int i = 1; i < n; ++i) {
            // Check up to k previous stones to find the minimal cost
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    dp[i] = std::min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
                }
            }
        }

        // The minimum cost to reach the last stone
        return dp[n - 1];
    }
};