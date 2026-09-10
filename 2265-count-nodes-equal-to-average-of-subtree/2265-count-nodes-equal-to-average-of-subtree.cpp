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

    pair<int,int> fun(TreeNode* root) {
 
        int sum = root->val,cnt = 1;
        if(root->left != NULL) {
            pair<int,int> pi = fun(root->left);
            sum += pi.first;
            cnt += pi.second;
        }
        if(root->right != NULL) {
            pair<int,int> pi = fun(root->right);
            sum += pi.first ;
            cnt += pi.second;
        }
        return {sum,cnt};
    }

    int dfs(TreeNode* root) {
        if(!root)
            return 0;

        int ways = 0;
        pair<int,int> l, r;
        if(root->left != NULL)
            l = fun(root->left);
        if(root->right !=NULL)
            r = fun(root->right);
        if((root->val+l.first+r.first)/(l.second+r.second+1)==root->val)
            ways += 1;
        ways += dfs(root->left);
        ways += dfs(root->right);
        return ways;
    }

    int averageOfSubtree(TreeNode* root) {
        return dfs(root);
    }
};