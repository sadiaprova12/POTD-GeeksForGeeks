class Solution {
    public:
      string longestPalindrome(string &s) {
          int start = 0, maxLength = 1;
          int n = s.length();
  
          // Helper function to expand around the center
          auto expandAroundCenter = [&](int left, int right) -> pair<int, int> {
              while (left >= 0 && right < n && s[left] == s[right]) {
                  left--;
                  right++;
              }
              return make_pair(left + 1, right - 1);
          };
  
          for (int i = 0; i < n; i++) {
              // Odd length palindrome
              pair<int, int> odd = expandAroundCenter(i, i);
              if (odd.second - odd.first + 1 > maxLength) {
                  start = odd.first;
                  maxLength = odd.second - odd.first + 1;
              }
              
              // Even length palindrome
              pair<int, int> even = expandAroundCenter(i, i + 1);
              if (even.second - even.first + 1 > maxLength) {
                  start = even.first;
                  maxLength = even.second - even.first + 1;
              }
          }
  
          return s.substr(start, maxLength);
      }
  };