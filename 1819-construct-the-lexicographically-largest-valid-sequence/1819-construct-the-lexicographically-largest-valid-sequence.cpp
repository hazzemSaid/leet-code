class Solution {
public:
    bool backtrack(int indx, int n, vector<int>& ans, vector<bool>& used) {
        int sz = ans.size();
        if (indx == sz) return true;
        if (ans[indx] != -1) 
            return backtrack(indx + 1, n, ans, used);
        for (int i = n; i >= 1; --i) {
            if (used[i]) continue;
            if (i == 1) {
                ans[indx] = 1;
                used[1] = true;
                if (backtrack(indx + 1, n, ans, used)) return true;
                ans[indx] = -1;
                used[1] = false;
            } else {
                if (indx + i < sz && ans[indx + i] == -1) {
                    ans[indx] = i;
                    ans[indx + i] = i;
                    used[i] = true;
                    if (backtrack(indx + 1, n, ans, used)) return true;
                    ans[indx] = -1;
                    ans[indx + i] = -1;
                    used[i] = false;
                }
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        int sz = 2 * n - 1;
        vector<int> ans(sz, -1);
        vector<bool> used(n + 1, false);  
        backtrack(0, n, ans, used);
        return ans;
    }
};
