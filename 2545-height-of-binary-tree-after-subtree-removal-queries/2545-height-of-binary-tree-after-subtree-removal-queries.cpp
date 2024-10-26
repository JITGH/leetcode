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
int maxHeightRemoval[100001];
int curMaxHeight=0;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverseLeftToRight(root,0);
        curMaxHeight=0;
        traverseRightToLeft(root,0);
        int queryCount=queries.size();
        vector<int> queryRes(queryCount);
        for(int i=0;i<queryCount;i++){
            queryRes[i]=maxHeightRemoval[queries[i]];
        }
        return queryRes;
    }
    private:
    void traverseLeftToRight(TreeNode* node,int current){
        if(node==NULL) return;
        maxHeightRemoval[node->val]=curMaxHeight;
        curMaxHeight=max(current,curMaxHeight);
        traverseLeftToRight(node->left,current+1);
        traverseLeftToRight(node->right,current+1);

    }

    void traverseRightToLeft(TreeNode* node,int current){
        if(node==NULL) return;
        maxHeightRemoval[node->val]=max(maxHeightRemoval[node->val],curMaxHeight);
        curMaxHeight=max(curMaxHeight,current);

        traverseRightToLeft(node->right,current+1);
        traverseRightToLeft(node->left,current+1);
    }

};