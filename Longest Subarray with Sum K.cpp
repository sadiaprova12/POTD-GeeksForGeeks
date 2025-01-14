class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        //code here
        unordered_map<int, int> prefixSumMap;
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < arr.size(); i++) {
            prefixSum += arr[i];

            // Check if the entire array up to index i has sum k
            if (prefixSum == k) {
                maxLength = i + 1;
            }

            // Check if prefixSum - k exists in the map
            if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[prefixSum - k]);
            }

            // Store the first occurrence of the prefix sum
            if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
                prefixSumMap[prefixSum] = i;
            }
        }

        return maxLength;
    }
};