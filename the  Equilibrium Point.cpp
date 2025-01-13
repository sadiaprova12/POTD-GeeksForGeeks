class Solution {
public:
    // Function to find the equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return -1; // No equilibrium point possible with less than 3 elements
        
        long long total_sum = accumulate(arr.begin(), arr.end(), 0LL);
        long long left_sum = 0;

        for (int i = 0; i < n; ++i) {
            long long right_sum = total_sum - left_sum - arr[i];
            if (left_sum == right_sum) return i;
            left_sum += arr[i];
        }

        return -1; // No equilibrium point found
    }
};