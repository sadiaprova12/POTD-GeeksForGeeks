class Solution {
    public:
      bool isBalanced(string& s) {
          stack<char> st;
          unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};
  
          for (char ch : s) {
              if (ch == '(' || ch == '{' || ch == '[') {
                  st.push(ch);
              } else {
                  if (st.empty() || st.top() != mapping[ch]) {
                      return false;
                  }
                  st.pop();
              }
          }
  
          return st.empty();
      }
  };