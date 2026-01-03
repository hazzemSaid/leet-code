class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int numOfWays(int n) {
        long long same = 6, diff = 6;

        for (int i = 1; i < n; i++) {
            long long newSame = (same * 3 + diff * 2) % MOD;
            long long newDiff = (same * 2 + diff * 2) % MOD;
            same = newSame;
            diff = newDiff;
        }

        return (same + diff) % MOD;
    }
};
