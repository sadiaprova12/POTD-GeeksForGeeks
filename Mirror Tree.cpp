class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if (node == NULL) return;

        // Swap the left and right subtrees
        swap(node->left, node->right);

        // Recursively call for left and right subtrees
        mirror(node->left);
        mirror(node->right);
    }
};
