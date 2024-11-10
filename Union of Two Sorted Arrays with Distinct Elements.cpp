class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        set<int>st(a.begin(),a.end());
        for(int i:b) st.insert(i);
        vector<int> ans(st.begin(),st.end());
        return ans;
    }
};