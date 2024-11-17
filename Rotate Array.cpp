class Solution {
  public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        // Normalize d to handle cases where d > n
        d = d % n;

        // Reverse the first d elements
        reverse(arr.begin(), arr.begin() + d);

        // Reverse the remaining n-d elements
        reverse(arr.begin() + d, arr.end());

        // Reverse the entire array
        reverse(arr.begin(), arr.end());
    }
};