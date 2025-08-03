class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // steps,take
        vector<pair<int, int>> l, r;
        int cnt = 0;
        for (auto& it : fruits) {
            int x = it[0];
            int t = it[1];
            if (x > startPos) {
                // more than
                r.push_back({x - startPos, t});
            } else if (x < startPos) {
                // less than
                l.push_back({startPos - x, t});

            } else {
                // equal
                cnt += t;
            }
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        for (int i = 1; i < l.size(); i++) {
            l[i].second += l[i - 1].second;
        }
        for (int i = 1; i < r.size(); i++) {
            r[i].second += r[i - 1].second;
        }
        int maxx = -1e9;
        for (auto& it : l) {
            if (it.first <= k) {
                maxx = max(maxx, it.second);
                int rlen = k - (it.first * 2);
                // can using the rlen for search into r
                if (rlen < 0)
                    continue;
                auto remindr = upper_bound(r.begin(), r.end(), rlen,
                                           [](const int& value,
                                              const std::pair<int, int>& elem) {
                                               return value < elem.first;
                                           }) -
                               r.begin() - 1;

                if (remindr >= 0 and r[remindr].first + it.first * 2 <= k)
                    maxx = max(maxx, it.second + r[remindr].second);
            }
        }
        cout << endl;
        for (auto& it : r) {
            if (it.first <= k) {
                maxx = max(maxx, it.second);
                int Llen = k - (it.first * 2);
                // can using the rlen for search into l
                if (Llen < 0)
                    continue;
                auto remindl = upper_bound(l.begin(), l.end(), Llen,
                                           [](const int& value,
                                              const std::pair<int, int>& elem) {
                                               return value < elem.first;
                                           }) -
                               l.begin() - 1;

                if (remindl >= 0 and l[remindl].first + it.first * 2 <= k)
                    maxx = max(maxx, it.second + l[remindl].second);
            }
        }
        return max(cnt, maxx + cnt);
    }
};