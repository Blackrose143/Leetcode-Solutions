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

    int fun(TreeNode* r) {
        if(!r)
            return 0;
        int ans = 0;
        ans = max(ans,fun(r->left)+1);
        ans = max(ans,fun(r->right)+1);
        return ans;
    }
    
    int maxDepth(TreeNode* root) {
        return fun(root);
    }
};