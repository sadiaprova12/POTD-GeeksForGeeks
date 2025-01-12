class Solution {
public:
    int maxWater(vector<int> &arr) {
        //code here
        int left = 0, right = arr.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate the current area
            int height = min(arr[left], arr[right]);
            int width = right - left;
            int currentArea = height * width;

            // Update maximum area
            maxArea = max(maxArea, currentArea);

            // Move the pointer pointing to the shorter line
            if (arr[left] < arr[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};