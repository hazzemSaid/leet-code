class Solution {
public:
    bool can(vector<int>& batt, long long mid, int n) {
        long long x = 0;
        int sz = batt.size();
        for (int i = 0; i < sz; i++) {
            x += min(batt[i] * 1ll, mid);
        }
        // cout<<x<<" "<<n*mid<<" "<<mid<<endl;;
        if (x >= n * mid)
            return true;
        return false;
    }
    long long binary_search(int n, vector<int>& batt) {
        long long l = 1, r = 0;
        for (auto& it : batt) {
            r += it;
        }
        r /= n;
        while (l < r) {
            long long mid = r - (r - l) / 2;
            bool c = can(batt, mid, n);
            if (c) {
                l = mid;
            } else
                r = mid - 1;
        }
        return l;
    }
    long long maxRunTime(int n, vector<int>& batt) {
        return binary_search(n, batt);
    }
};