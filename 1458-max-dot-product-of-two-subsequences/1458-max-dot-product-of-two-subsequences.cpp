class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if (i >= nums1.size() || j >= nums2.size())
            return INT_MIN;
        if (dp[i][j] != -1)
            return dp[i][j];
        int pick = nums1[i]*nums2[j]+max(0,solve(i+1,j+1,nums1,nums2));
        int skipi=solve(i+1,j,nums1,nums2);
        int skipj=solve(i,j+1,nums1,nums2);
        return dp[i][j]=max({pick,skipi,skipj});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp = vector<vector<int>>(501, vector<int>(501, -1));

        return solve(0, 0, nums1, nums2);
    }
};