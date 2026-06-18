
class Solution {
public:
     TreeNode*first=NULL;
     void markparent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent){
         if(root==NULL) return;
         if(root->left!=NULL){
            parent[root->left]=root;
         }
         if(root->right!=NULL){
            parent[root->right]=root;
         }
          markparent(root->left,parent);
         markparent(root->right,parent);
    }
    void find(TreeNode*root,int start){
        if(root==NULL)return ;
        if(root->val==start){
            first=root;
            return;
        }
        find(root->left,start);
        find(root->right,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        find(root,start);
        unordered_map<TreeNode*,TreeNode*>parent;
        markparent(root,parent);
        unordered_set<TreeNode*>s;
        s.insert(first);
        queue<pair<TreeNode*,int>>q;
        q.push({first,0});
        int maxlevel=0;
        while(q.size()>0){
            pair<TreeNode*,int>p=q.front();
            q.pop();
            int level=p.second;
            maxlevel=max(maxlevel,level);
            TreeNode*temp=p.first;
            if(temp->left!=NULL){
                if(s.find(temp->left)==s.end()){
                    q.push({temp->left,level+1});
                    s.insert(temp->left);
                }
            }
            if(temp->right!=NULL){
                if(s.find(temp->right)==s.end()){
                    q.push({temp->right,level+1});
                    s.insert(temp->right);
                }
            }
            if(parent.find(temp)!=parent.end()){
                if(s.find(parent[temp])==s.end()){
                    q.push({parent[temp],level+1});
                    s.insert(parent[temp]);
                }
            }
        }
        return maxlevel;
    }
};