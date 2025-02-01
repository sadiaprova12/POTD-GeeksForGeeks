class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        if (!root) return result; // Edge case: If tree is empty

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> levelNodes;

            for (int i = 0; i < levelSize; i++) {
                Node* current = q.front();
                q.pop();
                levelNodes.push_back(current->data);

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            result.push_back(levelNodes);
        }
        return result;
    }
};