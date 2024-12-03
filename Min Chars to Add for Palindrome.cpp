class Solution {
public:
    int minChar(string& s) {
        // Step 1: Create the combined string
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;

        // Step 2: Compute the LPS array
        int n = temp.size();
        vector<int> lps(n, 0);

        int len = 0, i = 1;
        while (i < n) {
            if (temp[i] == temp[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 3: Calculate the minimum characters to add
        return s.size() - lps.back();
    }
};