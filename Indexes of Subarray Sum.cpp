class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        //code here
        int n = arr.size();
        int left = 0, sum = 0;

        // Sliding window approach
        for (int right = 0; right < n; ++right) {
            sum += arr[right]; // Include current element in the sum
            
            // If sum exceeds target, shrink the window from the left
            while (sum > target && left <= right) {
                sum -= arr[left];
                left++;
            }

            // Check if the current window matches the target
            if (sum == target) {
                return {left + 1, right + 1}; // Convert to 1-based indexing
            }
        }

        // If no subarray found
        return {-1};
    }
};