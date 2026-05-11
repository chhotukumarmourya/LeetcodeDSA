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
    void helper(TreeNode* root,vector<int>&ans){
        if(root==NULL)return ;
        helper(root->left,ans);
        ans.push_back(root->val);
        helper(root->right,ans); 
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        helper(root,ans);
        int l=0;int r=ans.size()-1;
        while(l<r){
            int sum=ans[l]+ans[r];
            if(sum==k)return true;
            else if(sum<k)l++;
            else r--;
        }
        return false;
    }
};