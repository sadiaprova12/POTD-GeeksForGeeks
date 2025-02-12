class Solution {
    public:
      bool findTarget(Node* root, int target) {
          unordered_set<int> seen;
          return inorder(root, target, seen);
      }
  
    private:
      bool inorder(Node* root, int target, unordered_set<int>& seen) {
          if (!root) return false;
  
          // Check if complement (target - root->data) exists
          if (seen.count(target - root->data)) 
              return true;
          
          // Insert current node value into set
          seen.insert(root->data);
  
          // Recursively check left and right subtrees
          return inorder(root->left, target, seen) || inorder(root->right, target, seen);
      }
  };
  