class Solution {
public:
int mod = int(1e9)+7;
int fastPower( int b) {
    int a=2;
  if(b==0) return 1;
  int ans = fastPower(b/2);
  ans=(1ll*(ans%mod)*(ans%mod)*1ll)%mod;
  if(b&1)
    return ((a%mod)*(ans%mod))%mod;
  return ans;
}
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        set<int> s;
        int cnt = 0;
        while (n) {
            if (n % 2 == 1) {
                s.insert(cnt);
            }
            n /= 2;
            cnt ++;
        }
        vector<long long> nums;
        for (auto& it : s) {
            nums.push_back(it);
        }
        for (int i = 1; i < nums.size(); i++) {
            nums[i] =((nums[i]%int(1e9 + 7))+(nums[i - 1]%int(1e9 + 7)))%int(1e9 + 7);
        }
        vector<int> res;
        int q = queries.size();
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l == 0) {
                res.push_back(fastPower(nums[r]));
            } else
                res.push_back(fastPower(nums[r] -nums[l - 1]));
        }
        return res;
    };
};