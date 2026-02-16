class Solution {
public:
    int reverseBits(int n) {
        string nb = "";
        while (n) {
            if (n % 2 == 1) {
                nb += '1';
            } else
                nb += '0';
            n >>= 1;
        }
        for (int i = nb.size(); i < 32; i++) {
            nb = nb + '0';
        }
        reverse(nb.begin(), nb.end());
        int cnt = 1;
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (nb[i] == '1') {
                ans += cnt;
            }
            cnt <<= 1;
        }
        return ans;
    }
};