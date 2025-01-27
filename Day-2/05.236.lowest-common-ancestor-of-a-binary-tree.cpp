/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool exists(TreeNode* root, TreeNode* target){
        if(root==NULL) return false;
        if(root==target) return true; 
        if(exists(root->left,target)== true) return true; 
        if(exists(root->right,target)==true) return true; 

        else return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p or root==q) return root;
        else if(exists(root->left,p) and exists(root->right,q)) return root;
        else if(!exists(root->left,p) and !exists(root->right,q)) return root;
        else if(exists(root->left,p) and !exists(root->right,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);

    }
};
// @lc code=end

