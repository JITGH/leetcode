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
    private:
    int dfs_largesub(TreeNode* root,vector<int>&values){
        if(!root) return 0;
        int right=dfs_largesub(root->right,values);
        int left=dfs_largesub(root->left,values);

        int cnt=-1;
        if(right==left){
            cnt=(left+right)+1;
            values.push_back(cnt);
        }
        return cnt;
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int>values;
        int val=dfs_largesub(root,values);
        sort(values.begin(),values.end(),greater<int>());
        return k>values.size()?-1:values[k-1];
    }
};