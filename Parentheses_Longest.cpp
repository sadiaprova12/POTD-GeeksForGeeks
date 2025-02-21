class Solution {
    public:
      int maxLength(string& s) {
          stack<int> st;
          st.push(-1);  // Base index to calculate length
          int maxLen = 0;
  
          for (int i = 0; i < s.size(); i++) {
              if (s[i] == '(') {
                  st.push(i);
              } else {  // s[i] == ')'
                  st.pop();
                  if (st.empty()) {
                      st.push(i);  // Push current index as a new boundary
                  } else {
                      maxLen = max(maxLen, i - st.top());
                  }
              }
          }
          return maxLen;
      }
  };