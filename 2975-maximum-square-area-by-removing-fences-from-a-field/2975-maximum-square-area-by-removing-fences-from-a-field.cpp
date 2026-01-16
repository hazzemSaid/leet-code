class Solution {
public:
    const int MOD = int(1e9) + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hf, vector<int>& vf) {
     unordered_set<int> gapy;
    unordered_set<int> gapx;
        hf.push_back(1);
        hf.push_back(m);
        vf.push_back(n);
        vf.push_back(1);
        int hfs = hf.size();
        int vfs = vf.size();
        for (int i = 0; i < hfs; i++) {
            for (int j = i + 1; j < hfs; j++) {
                gapy.insert(abs(hf[j] - hf[i]));
            }
        }
        for (int i = 0; i < vfs; i++) {
            for (int j = i + 1; j < vfs; j++) {
                gapx.insert(abs(vf[j] - vf[i]));
            }
        }
        long long maxx = -1;
        for (auto& it : gapx) {
            if (gapy.find(it) != gapy.end())
                maxx = max(maxx,it*1ll);
        }
        if (maxx == -1)
            return -1;
        return ((maxx % MOD) * (maxx % MOD)) % MOD;
    }
};