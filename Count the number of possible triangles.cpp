class Solution {
public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        int count = 0;

        // Step 1: Sort the array
        sort(arr.begin(), arr.end());

        // Step 2: Iterate for each element as the largest side
        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;

            // Use two-pointer approach
            while (i < j) {
                if (arr[i] + arr[j] > arr[k]) {
                    // All pairs between i and j will form a valid triangle
                    count += (j - i);
                    j--; // Move the upper pointer to check for other pairs
                } else {
                    i++; // Move the lower pointer to increase the sum
                }
            }
        }

        return count;
    }
};