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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*>q;
        q.push(root);
        // TWO PASS OF BFS
        // vector<int>levelsum;
        // while(!q.empty()){
        //     int size=q.size();
        //     int lsum=0;
        //     for(int i=0;i<size;i++){
        //         TreeNode* node=q.front();
        //         q.pop();
        //         lsum+=node->val;
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        //     levelsum.push_back(lsum);
        // }

        // q.push(root);
        // int ind=1;
        // root->val=0;
        // while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0;i<size;i++){
        //         TreeNode* node=q.front();
        //         q.pop();
        //         int siblings=(node->left?node->left->val:0)+
        //         (node->right?node->right->val:0);

        //         if(node->left){
        //             node->left->val=levelsum[ind]-siblings;
        //             q.push(node->left);
        //         }
        //         if(node->right){
        //             node->right->val=levelsum[ind]-siblings;
        //             q.push(node->right);
        //         }
        //     }
        //     ind++;
        // }
        // return root;

        //BFS WITH RUNNING SUM

        int previoussum=root->val;
        
        while(!q.empty()){
            int size=q.size();
            queue<TreeNode*>current;
            int currsum=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                node->val=previoussum - node->val;

                int siblingsum=(node->left?node->left->val:0)+
                (node->right?node->right->val:0);

                if(node->left!=NULL){
                    currsum+=node->left->val;
                    node->left->val=siblingsum;
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    currsum+=node->right->val;
                    node->right->val=siblingsum;
                    q.push(node->right);
                }
            }
            previoussum=currsum;
        }
return root;
    }
};