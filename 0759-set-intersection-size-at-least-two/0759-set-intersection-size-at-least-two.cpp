class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& a) {
        int res = 0;
        sort(a.begin(), a.end(),
             [](const vector<int>& x, const vector<int>& y) {
                 if (x[1] == y[1])
                     return x[0] > y[0]; // DESC
                 return x[1] < y[1];     // ASC
             });
        int l = -1, r = -1;
        for (auto& it : a) {
            if (r < it[0]) {
                res += 2;
                l = it[1] - 1;
                r = it[1];
            } else if (l < it[0]) {
                res += 1;
                l = r;
                r = it[1];
            }
        }
        return res;
    }
};