class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // suf[i] = how many characters of word2
        // can be matched from word1[i...n-1]
        vector<int> suf(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = m - 1 - j;
        }
        // If even with one mismatch it is impossible
        if (m > n) return {};
        vector<int> ans;
        int p = 0;
        bool mismatchUsed = false;
        for (int i = 0; i < n && p < m; i++) {
            // Characters match
            if (word1[i] == word2[p]) {
                ans.push_back(i);
                p++;
            }
            // Characters don't match
            else if (!mismatchUsed) {
                // Use mismatch here if remaining characters
                // can still be matched
                int remaining = m - p - 1;
                if (suf[i + 1] >= remaining) {
                    ans.push_back(i);
                    p++;
                    mismatchUsed = true;
                }
            }
        }
        if (p == m)
            return ans;
        return {};
    }
};