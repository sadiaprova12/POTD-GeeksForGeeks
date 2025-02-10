class Solution {
    public:
      bool validateBST(Node* root, long long minVal, long long maxVal) {
          if (!root) return true;  // Base case: Empty tree is a valid BST
          
          if (root->data <= minVal || root->data >= maxVal) return false; // Check value range
  
          // Recur for left and right subtrees with updated constraints
          return validateBST(root->left, minVal, root->data) &&
                 validateBST(root->right, root->data, maxVal);
      }
  
      bool isBST(Node* root) {
          return validateBST(root, LLONG_MIN, LLONG_MAX); // Start with full range
      }
  };
  