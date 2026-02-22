class Solution {
public:
    int binaryGap(int n) {
        string sn = "";
        while (n) {
            if (n % 2 == 1) {
                sn += '1';
            } else
                sn += '0';
            n >>= 1;
        }
        int maxx = 0;
        int j = 0;
        reverse(sn.begin(), sn.end());
        for (int i = 1; i < sn.size(); i++) {
            if (sn[i] == '1') {
                maxx = max(maxx, i - j);
                j = i;
            }
        }
        return maxx;
    }
};