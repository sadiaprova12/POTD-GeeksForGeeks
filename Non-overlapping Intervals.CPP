class Solution {
public:
    int minRemoval(vector<vector<int>> &intervals) {
        // Sort intervals by their end times
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int nonOverlapCount = 0; // Count of non-overlapping intervals
        int end = INT_MIN; // Tracks the end of the last added interval

        for (const auto& interval : intervals) {
            if (interval[0] >= end) {
                // No overlap, include this interval
                end = interval[1];
            } else {
                // Overlap exists, remove this interval
                nonOverlapCount++;
            }
        }

        return nonOverlapCount;
    }
};
