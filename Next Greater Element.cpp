class Solution {
    public:
      // Function to find the next greater element for each element of the array.
      vector<int> nextLargerElement(vector<int>& arr) {
          int n = arr.size();
          vector<int> result(n, -1); // Initialize all elements with -1
          stack<int> st; // Stack to store the elements
          
          // Traverse the array from right to left
          for (int i = n - 1; i >= 0; i--) {
              // Pop elements from the stack that are smaller than or equal to arr[i]
              while (!st.empty() && st.top() <= arr[i]) {
                  st.pop();
              }
  
              // If stack is not empty, top is the next greater element
              if (!st.empty()) {
                  result[i] = st.top();
              }
  
              // Push current element to stack
              st.push(arr[i]);
          }
          return result;
      }
  };