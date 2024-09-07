/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
     
        if(!root) return false;

        // bool result=dfs(head,root);
        // result|=isSubPath(head,root->left);
        // result|=isSubPath(head,root->right);

        // return result;       

        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();

            if(isMatch(node,head)){
                return true;
            }
            if(node->left){
                st.push(node->left);
            } if(node->right){
                st.push(node->right);
            }
        } 

        return false;
    }

    // bool dfs(ListNode* head, TreeNode* node){
    //     if(!head) return true;
    //     if(!node) return false;
    //     bool result=false;
    //     if(node->val==head->val){
    //     result|=dfs(head->next,node->left);
    //     result|=dfs(head->next,node->right);
    //     }

    //     return result;
    // }

    bool isMatch( TreeNode* root,ListNode* cur){
        stack<pair<TreeNode*,ListNode*>>st;
        st.push({root,cur});

        while(!st.empty()){
            auto[curnode,curlist]=st.top();
            st.pop();
            while(curnode && curlist){
                if(curnode->val != curlist->val){
                    break;
                }
                curlist=curlist->next;
                if(curlist){
                    if(curnode->left){
                        st.push({curnode->left,curlist});
                    }if(curnode->right){
                        st.push({curnode->right,curlist});
                    }
                    break;
                }
            }

            if(!curlist){
                return true;
            }
        }
        return false;
    }
};