class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        if (node == nullptr) return -1; // Height in terms of edges
        return 1 + max(height(node->left), height(node->right));
    }
};