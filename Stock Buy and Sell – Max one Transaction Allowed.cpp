class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < n; i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                int profit = prices[i] - minPrice;
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};