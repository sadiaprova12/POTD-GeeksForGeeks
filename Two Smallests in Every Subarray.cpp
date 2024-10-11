class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        //code here
        int n = arr.size();
        
        if (n < 2) return -1;

        int maxSum = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            int currentSum = arr[i] + arr[i + 1];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};