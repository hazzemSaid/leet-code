class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int minn = INT_MAX;
        for (int i = 0; i <= sz - k; i++) {
            minn = min(nums[i + k - 1] - nums[i], minn);
        }
        return minn;
    }
};