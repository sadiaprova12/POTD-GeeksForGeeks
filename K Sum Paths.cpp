class Solution {
    public:
      int countPaths(Node* root, int k, long long currSum, unordered_map<long long, int> &prefixSum) {
          if (!root) return 0;
  
          // Update current sum
          currSum += root->data;
  
          // Count paths that sum to k
          int count = 0;
          if (prefixSum.find(currSum - k) != prefixSum.end()) {
              count += prefixSum[currSum - k];
          }
  
          // If the current sum itself is k, increment count
          if (currSum == k) count++;
  
          // Store current prefix sum
          prefixSum[currSum]++;
  
          // Recur for left and right subtrees
          count += countPaths(root->left, k, currSum, prefixSum);
          count += countPaths(root->right, k, currSum, prefixSum);
  
          // Backtrack (Remove the current prefix sum)
          prefixSum[currSum]--;
  
          return count;
      }
  
      int sumK(Node* root, int k) {
          unordered_map<long long, int> prefixSum;
          return countPaths(root, k, 0, prefixSum);
      }
  };
  