class Solution {
    public:
        int countPS(string &s) {
            int n = s.size();
            int count = 0;
    
            // Helper function to expand around the center
            auto expandAroundCenter = [&](int left, int right) {
                while (left >= 0 && right < n && s[left] == s[right]) {
                    if (right - left + 1 >= 2) // Only count palindromes with length ≥ 2
                        count++;
                    left--;
                    right++;
                }
            };
    
            // Iterate through each character and expand
            for (int i = 0; i < n; i++) {
                expandAroundCenter(i, i);     // Odd-length palindromes
                expandAroundCenter(i, i + 1); // Even-length palindromes
            }
    
            return count;
        }
    };