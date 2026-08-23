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

    int rec(TreeNode* r) {
        if(!r)
            return 0;
        int l = rec(r->left)+1;
        int h = rec(r->right)+1;
        return max(l,h);
    }

    bool fun(TreeNode* r) {
        if(!r)
            return true;
        int l = rec(r->left)+1;
        int h = rec(r->right)+1;
        if(abs(h-l)>1)
            return false;
        return fun(r->left) && fun(r->right);
    }

    bool isBalanced(TreeNode* root) {
        return fun(root);
    }
};