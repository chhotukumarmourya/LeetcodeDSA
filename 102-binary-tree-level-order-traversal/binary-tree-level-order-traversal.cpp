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
     int level(TreeNode*root){
        if(root==NULL)return 0;
        return 1+max(level(root->left),level(root->right));
     }
     
     void helper(TreeNode*root,vector<vector<int>> &ans,int level){
        if(root==NULL)return ;
        ans[level].push_back(root->val);
        helper(root->left,ans,level+1);
        helper(root->right,ans,level+1);
     }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n=level(root);
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
           ans.emplace_back(); 
        }
        helper(root,ans,0);
        return ans;
    }
};