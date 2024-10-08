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
    vector<double> averageOfLevels(TreeNode* root) {
       // if(root) return root;
        vector<double>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long temp=0;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

                temp+=node->val;

            }
            ans.push_back((double)temp/s);
        }
        return ans;
    }
};