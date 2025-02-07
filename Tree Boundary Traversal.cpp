class Solution {
    public:
      // Function to add left boundary nodes (excluding leaf nodes)
      void addLeftBoundary(Node* root, vector<int>& res) {
          Node* curr = root->left;
          while (curr) {
              if (!(curr->left == NULL && curr->right == NULL)) {
                  res.push_back(curr->data);
              }
              if (curr->left) curr = curr->left;
              else curr = curr->right;
          }
      }
  
      // Function to add leaf nodes (left-to-right)
      void addLeaves(Node* root, vector<int>& res) {
          if (!root) return;
          if (root->left == NULL && root->right == NULL) {
              res.push_back(root->data);
              return;
          }
          addLeaves(root->left, res);
          addLeaves(root->right, res);
      }
  
      // Function to add right boundary nodes (excluding leaf nodes, in reverse order)
      void addRightBoundary(Node* root, vector<int>& res) {
          Node* curr = root->right;
          vector<int> temp; // Store nodes to add them in reverse order
          while (curr) {
              if (!(curr->left == NULL && curr->right == NULL)) {
                  temp.push_back(curr->data);
              }
              if (curr->right) curr = curr->right;
              else curr = curr->left;
          }
          reverse(temp.begin(), temp.end());
          res.insert(res.end(), temp.begin(), temp.end());
      }
  
      // Main function to compute boundary traversal
      vector<int> boundaryTraversal(Node *root) {
          vector<int> res;
          if (!root) return res;
  
          // Step 1: Add root node (only if it's not a leaf)
          if (!(root->left == NULL && root->right == NULL)) {
              res.push_back(root->data);
          }
  
          // Step 2: Add left boundary
          addLeftBoundary(root, res);
  
          // Step 3: Add leaf nodes
          addLeaves(root, res);
  
          // Step 4: Add right boundary (in reverse order)
          addRightBoundary(root, res);
  
          return res;
      }
  };
  