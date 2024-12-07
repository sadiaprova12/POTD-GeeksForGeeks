class Solution {
public:
    // Function to count inversions in the array.
    int inversionCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp(n);
        return mergeSort(arr, temp, 0, n - 1);
    }

private:
    int mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
        int invCount = 0;
        if (left < right) {
            int mid = (left + right) / 2;

            // Count inversions in left and right halves
            invCount += mergeSort(arr, temp, left, mid);
            invCount += mergeSort(arr, temp, mid + 1, right);

            // Count split inversions
            invCount += merge(arr, temp, left, mid, right);
        }
        return invCount;
    }

    int merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
        int i = left;      // Left subarray index
        int j = mid + 1;   // Right subarray index
        int k = left;      // Merged array index
        int invCount = 0;

        // Merge both halves while counting inversions
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                // All remaining elements in left subarray are inversions
                invCount += (mid - i + 1);
                temp[k++] = arr[j++];
            }
        }

        // Copy remaining elements of left subarray
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements of right subarray
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy sorted subarray back into original array
        for (int z = left; z <= right; ++z) {
            arr[z] = temp[z];
        }

        return invCount;
    }
};
