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
    int maxLevelSum(TreeNode* root) {
        int maxi=INT_MIN;
        int ans=0;
        int level=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            level++;
            int cursum=0;
            for(int i=q.size();i>0;i--){
                TreeNode* it=q.front();
                q.pop();
                cursum+=it->val;

                if(it->left!=NULL){
                    q.push(it->left);
                }
                if(it->right!=NULL){
                    q.push(it->right);
                }
            }
            if(maxi<cursum){
                maxi=cursum;
                ans=level;
            }
        }
        return ans;
    }
};