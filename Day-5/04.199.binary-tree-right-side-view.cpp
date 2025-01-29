/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

// @lc code=start
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
    int level(TreeNode* root)
    {
        if(root==NULL) return 0; 
        return 1 + max(level(root->left),level(root->right)); 
    }

    void nthlevel(TreeNode* root , int current , int level,vector<int> &ans)
    {
        if(root==NULL) return;
        if(current==level) ans[current] = root->val;
        nthlevel(root->left,current+1,level,ans);
        nthlevel(root->right,current+1,level,ans);
    }

    void levelorder(TreeNode* root, vector<int> &ans)
    {
        int n = ans.size(); 

        for(int i = 0 ; i < n ; i++)
        {
            nthlevel(root,0,i,ans);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        int n = level(root);
        vector<int> ans(n,0);
        levelorder(root,ans);
        return ans;
    }
};
// @lc code=end

