class Solution {
public:
    int longestBalanced(string s) {
        int sz = s.size();
        int ans = 0;
        for (int i = 0; i < sz; i++) {
            map<char, int> mp;
            for (int j = i; j < sz; j++) {
                mp[s[j]]++;
                int x = mp[s[j]];
                bool valid = true;
                for (auto it : mp) {
                    if (x != it.second) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};