class Solution {
    public:
      int maxPathSumUtil(Node* root, int &maxSum) {
          if (!root) return 0;
  
          // Compute left and right max path sums
          int leftSum = max(0, maxPathSumUtil(root->left, maxSum));
          int rightSum = max(0, maxPathSumUtil(root->right, maxSum));
  
          // Update global max sum considering the path through the current node
          maxSum = max(maxSum, leftSum + rightSum + root->data);
  
          // Return the max path sum that can be extended to the parent node
          return root->data + max(leftSum, rightSum);
      }
  
      int findMaxSum(Node* root) {
          int maxSum = INT_MIN;  // Initialize to smallest possible value
          maxPathSumUtil(root, maxSum);
          return maxSum;
      }
  };
  