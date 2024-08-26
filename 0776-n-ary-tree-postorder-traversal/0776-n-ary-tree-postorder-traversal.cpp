/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        posttree(root,ans);

        return ans;
    }

    void posttree(Node* root,vector<int>&ans){
        if(root==NULL) return;
        for(Node* child:root->children){
            posttree(child,ans);
        }
        ans.push_back(root->val);
    }
};