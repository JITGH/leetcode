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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxsum(root,maxi);
        return maxi;
    }
    int maxsum(TreeNode* node,int &maxi){
        if(node==NULL) return 0;
        int LeftSum=max(0,maxsum(node->left,maxi));
        int RightSum=max(0,maxsum(node->right,maxi));
        maxi=max(maxi,(LeftSum+RightSum+node->val));
        return max(LeftSum,RightSum)+node->val;
    }
};