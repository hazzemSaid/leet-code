class Solution {
public:
    long long totalSum = 0;
    long long ans = 0;
    const int MOD = 1e9 + 7;

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        // try cutting here
        ans = max(ans, subSum * (totalSum - subSum));

        return subSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = dfs(root);  
        dfs(root);             
        return ans % MOD;
    }
};
