class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz, 0);
        unordered_map<int, int> mp;
        for (int i = 0; i < sz; i++)
            mp[i] = nums[i];
        for (int i = 0; i < sz; i++) {
            if (nums[i] < 0) {
                res[i] = mp[((i - abs(nums[i])) + sz*100) % sz];
            }
            if (nums[i] > 0) {
                res[i] = mp[((i + (nums[i])) + sz*100) % sz];
            }
            if (nums[i] == 0) {
                res[i] = mp[i];
            }
        }
        return res;
    }
};