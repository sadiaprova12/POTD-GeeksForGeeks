
class Solution {
  public:
    // Helper function to compute height and update diameter
    int heightAndDiameter(Node* node, int &diameter) {
        if (node == nullptr) return 0;

        // Compute height of left and right subtrees
        int leftHeight = heightAndDiameter(node->left, diameter);
        int rightHeight = heightAndDiameter(node->right, diameter);

        // Update diameter: max of itself and (leftHeight + rightHeight)
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height of the current node
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to find the diameter of the binary tree
    int diameter(Node* root) {
        int diameter = 0;
        heightAndDiameter(root, diameter);
        return diameter;
    }
};