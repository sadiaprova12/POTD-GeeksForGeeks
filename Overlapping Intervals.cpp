class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Sort intervals based on start time
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> merged;
        for (const auto& interval : arr) {
            // If merged is empty or no overlap, add interval to merged
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            } else {
                // Overlap exists; merge intervals
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};