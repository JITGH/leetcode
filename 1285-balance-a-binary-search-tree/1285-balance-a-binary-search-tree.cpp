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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        inorderTraversal(root,inorder);
        int size=inorder.size();
        return balancetree(inorder,0,size-1);

    }
    private:
    void inorderTraversal(TreeNode* root,vector<int>&inorder){
        if(root==NULL) return ;
        inorderTraversal(root->left,inorder);
        inorder.push_back(root->val);
        inorderTraversal(root->right,inorder);
    }

    TreeNode* balancetree(const vector<int>&inorder,int start,int end){
        if(start>end) return NULL;

        int mid=start+(end-start)/2;

        TreeNode* leftsubtree=balancetree(inorder,start,mid-1);
        TreeNode* rightsubtree=balancetree(inorder,mid+1,end);

        return new TreeNode(inorder[mid],leftsubtree,rightsubtree);;
    }
};