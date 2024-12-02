class Solution {
public:
    vector<int> search(string& pat, string& txt) {
        vector<int> result; // To store the starting indices of pattern matches
        int n = txt.size(), m = pat.size();
        
        // Step 1: Create the LPS (Longest Prefix Suffix) array for the pattern
        vector<int> lps(m, 0);
        int len = 0, i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
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
        
        // Step 2: Search for the pattern in the text using the LPS array
        i = 0; // Index for txt
        int j = 0; // Index for pat
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            
            if (j == m) {
                // Found a match; store the starting index
                result.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pat[j] != txt[i]) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        
        return result;
    }
};