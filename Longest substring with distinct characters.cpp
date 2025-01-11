class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        //code here.
        unordered_map<char, int> lastIndex; // To store the last occurrence of characters
        int maxLength = 0; // To keep track of the maximum length of substring
        int start = 0; // Sliding window start index

        for (int end = 0; end < s.size(); end++) {
            char currentChar = s[end];

            // If the current character is already in the map and its last index is within the current window
            if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= start) {
                start = lastIndex[currentChar] + 1; // Move the start of the window
            }

            lastIndex[currentChar] = end; // Update the last seen index of the current character
            maxLength = max(maxLength, end - start + 1); // Update the maximum length
        }

        return maxLength;
    }
};