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
    long long kthLargestLevelSum(TreeNode* root, int k) {
      //  priority_queue<long>pq;
      priority_queue<long,vector<long>,greater<long>>pq;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long size=q.size();
            long sum=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
               
                q.pop();
                 sum+=node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }if(node->right!=NULL){
                    q.push(node->right);
                }

            }
            pq.push(sum);
             if(pq.size()>k) pq.pop();
        }
        // if(pq.size()<k) return -1;
        // for(int i=0;i<k-1;i++) pq.pop();
        // return pq.top();

       
        if(pq.size()<k) return -1;
        return pq.top();
    }
};