class Solution {
public:
    int countPairs(vector<int>& arr, int target) {
        //complete the function
        int n = arr.size();
        if (n < 2) return 0; // No pairs can be formed
        
        int i = 0, j = n - 1;
        int count = 0;
        
        while (i < j) {
            int sum = arr[i] + arr[j];
            
            if (sum == target) {
                // Count the pairs formed with duplicates
                if (arr[i] == arr[j]) {
                    // If both elements are the same, calculate combinations
                    int freq = j - i + 1;
                    count += (freq * (freq - 1)) / 2;
                    break; // All pairs with these elements are counted
                } else {
                    // Count pairs with distinct elements
                    int leftCount = 1, rightCount = 1;
                    
                    // Count duplicates for arr[i]
                    while (i + 1 < j && arr[i] == arr[i + 1]) {
                        leftCount++;
                        i++;
                    }
                    
                    // Count duplicates for arr[j]
                    while (j - 1 > i && arr[j] == arr[j - 1]) {
                        rightCount++;
                        j--;
                    }
                    
                    // Add the combinations of pairs
                    count += leftCount * rightCount;
                    
                    // Move the pointers
                    i++;
                    j--;
                }
            } else if (sum < target) {
                i++; // Move toward a larger sum
            } else {
                j--; // Move toward a smaller sum
            }
        }
        
        return count;
    }
};