/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> in;
    void in_ordered(TreeNode* root) {
        if (!root)
            return;
        in_ordered(root->left);
        in.push_back(root->val);
        in_ordered(root->right);
    }
    TreeNode* build(int l, int r) {
        if (l > r)
            return NULL;
        int m = (l + r) / 2;
        TreeNode* root = new TreeNode(in[m]);
        root->left = build(l, m - 1);
        root->right = build(m + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        in_ordered(root);
        return build(0, in.size() - 1);
    }
};