class Solution {
  public:
    int getMinDiff(int k, vector<int>& arr) {
        // Code Here
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int minDiff = arr[n - 1] - arr[0]; 
        
        for (int i = 0; i < n - 1; i++) {
            int high = max(arr[n - 1] - k, arr[i] + k);
            int low = min(arr[0] + k, arr[i + 1] - k);

            minDiff = min(minDiff, high - low);
        }

        return minDiff;
    }
};