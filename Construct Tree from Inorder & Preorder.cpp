class Solution {
  public:
    // Helper function to build the tree
    Node* buildTreeHelper(vector<int>& inorder, vector<int>& preorder, 
                          int inStart, int inEnd, int& preIndex, unordered_map<int, int>& inMap) {
        // Base case: If there are no elements to construct the tree
        if (inStart > inEnd) return NULL;

        // Pick the current node from preorder traversal
        int rootValue = preorder[preIndex++];
        Node* root = new Node(rootValue);

        // Find the index of this node in inorder traversal
        int inIndex = inMap[rootValue];

        // Recursively construct the left and right subtrees
        root->left = buildTreeHelper(inorder, preorder, inStart, inIndex - 1, preIndex, inMap);
        root->right = buildTreeHelper(inorder, preorder, inIndex + 1, inEnd, preIndex, inMap);

        return root;
    }

    // Function to build the tree from inorder and preorder traversals
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int preIndex = 0;
        unordered_map<int, int> inMap;

        // Store the index of each value in inorder for quick lookup
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(inorder, preorder, 0, inorder.size() - 1, preIndex, inMap);
    }
};
