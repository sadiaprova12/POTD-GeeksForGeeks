class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long ans = 0;
        unordered_map<int, int> mp;
        int currXOR = 0;
        mp[0] = 1;

        for (int i : arr) {
            currXOR ^= i;

            // Check if (currXOR ^ k) exists in the map
            if (mp.find(currXOR ^ k) != mp.end()) {
                ans += mp[currXOR ^ k];
            }

            // Update the frequency of the current XOR
            mp[currXOR]++;
        }

        return ans;
    }
};