class Solution {
    public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          priority_queue<pair<int, vector<int>>> maxHeap;
  
          for (auto& p : points) {
              int x = p[0], y = p[1];
              int dist = x * x + y * y; // Squared distance (No sqrt needed)
              
              maxHeap.push({dist, p});
              if (maxHeap.size() > k) {
                  maxHeap.pop(); // Remove farthest point
              }
          }
  
          vector<vector<int>> result;
          while (!maxHeap.empty()) {
              result.push_back(maxHeap.top().second);
              maxHeap.pop();
          }
  
          return result; // No need to sort as required by the problem
      }
  };