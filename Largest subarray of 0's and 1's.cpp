class Solution {
  public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> prefixSumIndex; // To store cumulative sum and its first index
        int maxLength = 0;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            // Replace 0 with -1
            sum += (arr[i] == 0) ? -1 : 1;

            // Check if cumulative sum is 0
            if (sum == 0) {
                maxLength = i + 1;
            }

            // Check if this sum has been seen before
            if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
                maxLength = max(maxLength, i - prefixSumIndex[sum]);
            } else {
                // Store the first occurrence of this sum
                prefixSumIndex[sum] = i;
            }
        }

        return maxLength;
    }
};