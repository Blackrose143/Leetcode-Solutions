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

    int t;
    vector<vector<int>> ans;
    void fun(TreeNode* root,vector<int>& cur) {
    
        if(!root->left && !root->right) {
            int sum = accumulate(cur.begin(),cur.end(),0LL);
            if(sum==t)
                ans.push_back(cur);
            return ;
        }

        if(root->left) {
            cur.push_back(root->left->val);
            fun(root->left,cur);
            cur.pop_back();
        }
        if(root->right) {
            cur.push_back(root->right->val);
            fun(root->right,cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return {};
        t = targetSum;
        vector<int> res;
        res.push_back(root->val);
        fun(root,res);
        return ans;
    }
};