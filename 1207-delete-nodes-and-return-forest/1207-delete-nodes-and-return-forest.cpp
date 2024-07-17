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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        set<int>del;
        for(int i:to_delete){
            del.insert(i);
        }

        removenodes(root,del,ans);
        if(del.find(root->val)==del.end()){
            ans.push_back(root);
        }
        return ans;
    }

    TreeNode* removenodes(TreeNode* root, set<int>&del,vector<TreeNode*>&ans){
        if(root==NULL) return NULL;
        root->left=removenodes(root->left,del,ans);
        root->right=removenodes(root->right,del,ans);

        if(del.find(root->val)!=del.end()){
            if(root->left!=NULL){
                ans.push_back(root->left);
            }if(root->right!=NULL){
                ans.push_back(root->right);
            }
            return NULL;
            }

            return root;
        }
    
};