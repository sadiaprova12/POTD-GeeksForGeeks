class Solution {
public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        //code here
        int n = arr.size();
        if (n < 2) return {}; 
        
        // Sort the array
        sort(arr.begin(), arr.end());
        
        int left = 0, right = n - 1;
        int closestSum = INT_MAX;  
        int maxAbsDiff = -1;       
        vector<int> result;        
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            
            // Check if this sum is closer to the target
            if (abs(target - sum) < abs(target - closestSum) || 
                (abs(target - sum) == abs(target - closestSum) && abs(arr[right] - arr[left]) > maxAbsDiff)) {
                closestSum = sum;
                maxAbsDiff = abs(arr[right] - arr[left]);
                result = {arr[left], arr[right]};
            }
            
            // Move pointers
            if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return result;
    }
};