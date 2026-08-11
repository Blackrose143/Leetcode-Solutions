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

    int k;
    vector<vector<int>> ans;
    void fun(TreeNode* root,vector<int>& nums,int sum) {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            nums.push_back(root->val);
            sum += root->val;
            if(sum==k)
                ans.push_back(nums);
            nums.pop_back();
            return;
        }
        if(root->left!=NULL){
            nums.push_back(root->val);
            fun(root->left,nums,sum+root->val);
            nums.pop_back();
        }
        if(root->right!=NULL){
            nums.push_back(root->val);
            fun(root->right,nums,sum+root->val);
            nums.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        k = targetSum;
        vector<int> nums;
        fun(root,nums,0);
        return ans;
    }
};