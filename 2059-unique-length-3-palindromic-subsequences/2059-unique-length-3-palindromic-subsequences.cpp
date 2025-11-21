class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<int>> prf(n, vector<int>(26, 0));
        vector<vector<int>> suf(n, vector<int>(26, 0));

        // Prefix counts
        for (int i = 0; i < n; i++) {
            if (i > 0) prf[i] = prf[i-1];
            prf[i][s[i] - 'a']++;
        }

        // Suffix counts
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) suf[i] = suf[i+1];
            suf[i][s[i] - 'a']++;
        }

        // Track which palindromes we’ve counted
        vector<vector<bool>> counted(26, vector<bool>(26, false));
        int ans = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int c = 0; c < 26; c++) {
                // Check if character c exists before and after s[i]
                if (prf[i-1][c] > 0 && suf[i+1][c] > 0) {
                    if (!counted[c][s[i]-'a']) {
                        counted[c][s[i]-'a'] = true;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
