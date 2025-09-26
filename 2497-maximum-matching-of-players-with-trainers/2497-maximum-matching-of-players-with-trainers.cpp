class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int ans = 0;
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        for (int i = 0, j = 0; j < t.size() && i < p.size();) {
            while (j < t.size() and p[i] > t[j]) {
                j++;
            }
            if (j < t.size() and p[i] <= t[j]) {
                ans++;
                j++;
                i++;
            }
        }
        return ans;
    }
};