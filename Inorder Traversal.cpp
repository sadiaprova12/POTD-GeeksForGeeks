class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void inorderHelper(Node* root, vector<int>& result) {
        if (root == NULL) return;

        // Recur on the left subtree
        inorderHelper(root->left, result);

        // Store the root node's value
        result.push_back(root->data);

        // Recur on the right subtree
        inorderHelper(root->right, result);
    }

    vector<int> inOrder(Node* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
};
