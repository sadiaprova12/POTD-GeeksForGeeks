class Solution {
    public:
      Node *first = NULL, *second = NULL, *prev = NULL;
  
      void inorder(Node* root) {
          if (!root) return;
  
          inorder(root->left);
  
          // Detect swapped nodes
          if (prev && prev->data > root->data) {
              if (!first) first = prev; // First violation
              second = root; // Second violation
          }
          prev = root; // Move to next node
  
          inorder(root->right);
      }
  
      void correctBST(Node* root) {
          inorder(root);
          if (first && second) swap(first->data, second->data); // Fix swapped nodes
      }
  };
  