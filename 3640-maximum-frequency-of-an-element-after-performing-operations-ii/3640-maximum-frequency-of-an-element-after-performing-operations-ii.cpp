class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<long long, long long> mp;
        vector<pair<long long, long long>> v;
        set<long long> point;
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        // point, +/- 1
        //         (s->+ , e->-1)
        for (auto& it : nums) {
            mp[it]++;
            // s == nums[i]-k
            // d == nums[i]
            // e == nums[i]+k+1
            v.push_back({it - k, 1});
            v.push_back({it + k + 1, -1});
            point.insert(it);
            point.insert(it + k + 1);
            point.insert(it - k);
        }
        sort(v.begin(), v.end());
        long long ans = 0, maxfrq = 1, id = 0, overlapcounter = 0;
        for (auto& it : point) {
            while (id < v.size() and v[id].first <= it) {
                overlapcounter += v[id].second; //+1 or -1
                id++;
            }
            long long cur = mp[it] + min(numOperations * 1ll,
                                         max(0 * 1ll, overlapcounter - mp[it]));
            maxfrq = max(maxfrq, cur);
        }
        return maxfrq;
    }
};