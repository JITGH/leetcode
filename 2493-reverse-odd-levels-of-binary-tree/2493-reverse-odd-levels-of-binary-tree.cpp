/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    private:
        void dfs(TreeNode* leftChild,TreeNode* rightChild,int level){
            if(leftChild==nullptr &&rightChild==nullptr) return;

            if(level%2==0){
                int temp=leftChild->val;
                leftChild->val=rightChild->val;
                rightChild->val=temp;
            }
            dfs(leftChild->left,rightChild->right,level+1);
            dfs(leftChild->right,rightChild->left,level+1);
        }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        // if (root == nullptr)
        //     return nullptr;

            //BFS
        //  if(root->left==nullptr && root->right==nullptr) return root;
        // int level = 0;
        // queue<TreeNode*> q;
        // q.push(root);
        // while (!q.empty()) {
        //     auto size = q.size();
        //     vector<TreeNode*> nodes;
        //     while (size--) {
        //         TreeNode* currentNode = q.front();
        //         q.pop();
        //         nodes.push_back(currentNode);

        //         if(currentNode->left) q.push(currentNode->left);
        //         if(currentNode->right)  q.push(currentNode->right);
        //     }
        //     if (level % 2 ==1) {
        //         int left = 0;
        //         int right = nodes.size() - 1;
        //         while (left < right) {
        //             swap(nodes[left]->val, nodes[right]->val);
        //             left++;
        //             right--;
        //         }
        //     }
        //     level++;
        // }
        // return root;

        dfs(root->left,root->right,0);
        return root;
    }
};