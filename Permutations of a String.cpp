class Solution {
public:
    void backtrack(string &s, vector<string> &result, string &current, vector<bool> &used) {
        if (current.size() == s.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < s.size(); i++) {
            // Skip used characters
            if (used[i]) continue;

            // Skip duplicates: If the current character is the same as the previous one and the previous one has not been used, skip it.
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;

            // Choose the current character
            used[i] = true;
            current.push_back(s[i]);

            // Recurse
            backtrack(s, result, current, used);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }

    vector<string> findPermutation(string &s) {
        vector<string> result;
        string current;

        // Sort the string to handle duplicates
        sort(s.begin(), s.end());

        // Used array to track characters
        vector<bool> used(s.size(), false);

        // Start backtracking
        backtrack(s, result, current, used);

        return result;
    }
};
