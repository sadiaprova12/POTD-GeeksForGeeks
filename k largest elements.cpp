class Solution {
    public:
      vector<int> kLargest(vector<int>& arr, int k) {
          priority_queue<int, vector<int>, greater<int>> minHeap; // Min Heap
          
          for (int num : arr) {
              minHeap.push(num);
              if (minHeap.size() > k) {
                  minHeap.pop(); // Remove the smallest element
              }
          }
  
          vector<int> result;
          while (!minHeap.empty()) {
              result.push_back(minHeap.top());
              minHeap.pop();
          }
  
          reverse(result.begin(), result.end()); // Descending order
          return result;
      }
  };
  