class Solution {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          // Base case: If root is null
          if (!root) return NULL;
  
          // If both n1 and n2 are smaller than root, LCA is in the left subtree
          if (root->data > n1->data && root->data > n2->data) {
              return LCA(root->left, n1, n2);
          }
          
          // If both n1 and n2 are greater than root, LCA is in the right subtree
          if (root->data < n1->data && root->data < n2->data) {
              return LCA(root->right, n1, n2);
          }
          
          // If root is between n1 and n2, it is the LCA
          return root;
      }
  };
  