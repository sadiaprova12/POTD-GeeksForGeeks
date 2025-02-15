class Solution {
    public:
      // Function to serialize a tree and return a list containing nodes of tree.
      vector<int> serialize(Node *root) {
          vector<int> result;
          if (!root) return result;
          
          queue<Node*> q;
          q.push(root);
          
          while (!q.empty()) {
              Node* node = q.front();
              q.pop();
              
              if (node) {
                  result.push_back(node->data);
                  q.push(node->left);
                  q.push(node->right);
              } else {
                  result.push_back(-1);  // Marker for NULL
              }
          }
          return result;
      }
  
      // Function to deserialize a list and construct the tree.
      Node* deSerialize(vector<int> &arr) {
          if (arr.empty()) return NULL;
  
          queue<Node*> q;
          Node* root = new Node(arr[0]);
          q.push(root);
          
          int i = 1;
          while (!q.empty() && i < arr.size()) {
              Node* node = q.front();
              q.pop();
              
              // Left child
              if (arr[i] != -1) {
                  node->left = new Node(arr[i]);
                  q.push(node->left);
              }
              i++;
              
              // Right child
              if (i < arr.size() && arr[i] != -1) {
                  node->right = new Node(arr[i]);
                  q.push(node->right);
              }
              i++;
          }
          return root;
      }
  };
  