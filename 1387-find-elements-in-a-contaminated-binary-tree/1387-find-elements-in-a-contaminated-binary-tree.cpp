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
class FindElements {
    unordered_set<int>st;
public:
    void recover(TreeNode* node,int num){
        if(!node) return;
        node->val=num;
        st.insert(num);
        recover(node->left,2*num+1);
        recover(node->right,2*num+2);
    }
    FindElements(TreeNode* root) {
        recover(root,0);
    }
    
    bool find(int target) {
        if(st.find(target)==st.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */