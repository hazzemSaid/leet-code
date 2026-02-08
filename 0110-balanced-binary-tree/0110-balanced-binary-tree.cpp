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
bool lol=true;
    int dpth(TreeNode* root) {
        if (!root)
            return 0;
        int left = 0, right = 0;
        if (root->left)
            left = dpth(root->left);
        if (root->right)
            right = dpth(root->right);
        if(abs(left-right)>1)lol=false;
        return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int x = dpth(root->left);
        int y = dpth(root->right);

        return (lol and abs(x - y) <= 1);
    }
};