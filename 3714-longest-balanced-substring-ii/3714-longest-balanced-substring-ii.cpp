class Solution {
public:
    int fun(int& cnt, string f, string s) {
        int maxx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (f.find(s[i]) == string::npos) {
                cnt = 0;
            } else {
                cnt++;
            }
            maxx = max(cnt, maxx);
        }
        return maxx;
    }
    int fun2(string& s, char c1, char c2, char forbidden) {
        int maxx = 0;
        int diff = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == forbidden) {
                mp.clear();
                mp[0] = i;
                diff = 0;
            } else {
                if (s[i] == c1)
                    diff++;
                else if (s[i] == c2)
                    diff--;

                if (mp.count(diff)) {
                    maxx = max(maxx, i - mp[diff]);
                } else {
                    mp[diff] = i;
                }
            }
        }
        return maxx;
    }
    int longestBalanced(string s) {
        map<pair<int, int>, int> mp;
        int sz = s.size();
        int cnta = 0, cntb = 0, cntc = 0;
        int maxx = 0;
        mp[{0, 0}] = -1;
        for (int i = 0; i < sz; i++) {
            if (s[i] == 'a')
                cnta++;
            if (s[i] == 'b')
                cntb++;
            if (s[i] == 'c')
                cntc++;
            if (mp.find({cntb - cnta, cntc - cnta}) != mp.end()) {
                maxx = max(maxx, i - mp[{cntb - cnta, cntc - cnta}]);
            }
            else
            mp[{cntb - cnta, cntc - cnta}] = i;
        }
        cnta = 0, cntb = 0, cntc = 0;

        maxx = max({maxx, fun2(s, 'a', 'b', 'c'), fun2(s, 'a', 'c', 'b'),
                    fun2(s, 'c', 'b', 'a'), fun(cnta, "a", s),
                    fun(cntb, "b", s), fun(cntc, "c", s)});
        return maxx;
    }
};