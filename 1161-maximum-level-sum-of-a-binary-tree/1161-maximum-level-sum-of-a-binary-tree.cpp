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
    int maxLevelSum(TreeNode* root) {
        long long maxx = INT_MIN;
        int levelnum = 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int level = 0;
        while (!qu.empty()) {
            int sz = qu.size();
            long long sumlevel = 0;
            level++;
            for (int i = 0; i < sz; i++) {
                auto it = qu.front();
                qu.pop();
                sumlevel += it->val * 1ll;
                if (it->left)
                    qu.push(it->left);
                if (it->right)
                    qu.push(it->right);
            }
            if (maxx < sumlevel) {
                maxx = sumlevel;
                levelnum = level;
            }
        }
        return levelnum;
    }
};