class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        //code here
        unordered_set<int> seen; // A set to track unique elements
        vector<int> result;      // Result vector to store unique elements

        for (int num : arr) {
            if (seen.find(num) == seen.end()) { // If num is not in seen
                seen.insert(num);               // Insert num into seen
                result.push_back(num);          // Add num to result
            }
        }

        return result;
    }
};