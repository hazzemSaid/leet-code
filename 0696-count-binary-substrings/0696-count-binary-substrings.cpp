class Solution {
public:
    int countBinarySubstrings(string s) {
        int sz = s.size(),ans=0;
        vector<int> prfz(sz + 2, 0), sufz(sz + 2, 0);
        vector<int> prfo(sz + 2, 0), sufo(sz + 2, 0);
        for (int i = 0; i < sz; i++) {
            if (s[i] == '0') {
                prfz[i] = 1;
                sufz[i] = 1;
            }
        }
        for (int i = 0; i < sz; i++) {
            if (s[i] == '1') {
                prfo[i] = 1;
                sufo[i] = 1;
            }
        }
        for (int i = 0; i < sz - 1; i++) {
            if (s[i + 1] == '1')
                continue;
            prfz[i + 1] += prfz[i];
        }
        for (int i = sz - 2; i >= 0; i--) {
            if (s[i] == '1')
                continue;
            sufz[i] += sufz[i + 1];
        }
        // for (int i = 0; i < sz; i++)
        //     cout << prfz[i] << " ";
        // cout << endl;
        // for (int i = 0; i < sz; i++)
        //     cout << sufz[i] << " ";
        // cout << endl;

        for (int i = 0; i < sz - 1; i++) {
            if (s[i + 1] == '0')
                continue;
            prfo[i + 1] += prfo[i];
        }
        for (int i = sz - 2; i >= 0; i--) {
            if (s[i] == '0')
                continue;
            sufo[i] += sufo[i + 1];
        }
        // for (int i = 0; i < sz; i++)
        //     cout << prfo[i] << " ";
        // cout << endl;
        // for (int i = 0; i < sz; i++)
        //     cout << sufo[i] << " ";
        
        for(int i=0;i<sz-1;i++){
            ans+=min(prfz[i],sufo[i+1]);
        }
         for(int i=0;i<sz-1;i++){
            ans+=min(prfo[i],sufz[i+1]);
        }
        return ans;
    }
};