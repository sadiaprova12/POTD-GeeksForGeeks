class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        //code here.
        vector<int> result;
        unordered_map<int, int> freqMap; // To store the frequency of elements in the current window
        int n = arr.size();

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            freqMap[arr[i]]++;
        }
        result.push_back(freqMap.size()); // Add the count of distinct elements in the first window

        // Slide the window
        for (int i = k; i < n; i++) {
            // Remove the element that goes out of the window
            freqMap[arr[i - k]]--;
            if (freqMap[arr[i - k]] == 0) {
                freqMap.erase(arr[i - k]); // Remove the element from the map if its frequency is 0
            }

            // Add the new element to the window
            freqMap[arr[i]]++;

            // Store the distinct count for the current window
            result.push_back(freqMap.size());
        }

        return result;
    }
};