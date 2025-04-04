/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* ans;
int max_depth=0;
int fun(TreeNode* subroot,int depth){
    if(subroot== NULL) 
    {
        return depth-1;
    }
    int depthlf=0,depthrg=0;
        depthlf =fun(subroot->left,depth+1);
        depthrg =fun(subroot->right,depth+1);
    // cout<<subroot->val<<" ";
    // cout<<depthrg<<" "<<depthlf<<" "<<depth<<" ";
    // cout<<endl;
    if(depthrg == depthlf and depthlf>=max_depth){
        ans=subroot;
        max_depth=depthlf;
    }
    return max(depthrg,depthlf);
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
       int x =fun(root,0);
       cout<<'x'<<" "<<x<<endl;
        return ans;
    }
};