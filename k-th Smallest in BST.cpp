class Solution {
    public:
      // Function to find the kth smallest element in BST
      int kthSmallest(Node* root, int k) {
          int count = 0;  // Counter to track number of nodes visited
          int result = -1;
          inorder(root, k, count, result);
          return result;
      }
  
    private:
      void inorder(Node* root, int k, int& count, int& result) {
          if (!root || count >= k) return; // Base case
          
          // Traverse the left subtree
          inorder(root->left, k, count, result);
          
          // Process the current node
          count++;
          if (count == k) {
              result = root->data;
              return;
          }
          
          // Traverse the right subtree
          inorder(root->right, k, count, result);
      }
  };
  