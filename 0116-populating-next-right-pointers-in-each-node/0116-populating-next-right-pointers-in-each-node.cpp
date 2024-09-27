/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      //  vector<Node*>result;
        if(root==NULL || (root->right==NULL && root->left ==NULL)) return root;
        queue<Node*>q;
        q.push(root);
       // q.pop();
        while(!q.empty()){
            int size=q.size();
            Node* track=NULL;
            for(int i=0;i<size;i++){
           auto it=q.front();
        //    q.pop();
        if(track!=NULL){
            track->next=it;
        }
           track=it;
        
           
           if(it->left){
           q.push(it->left);
           q.push(it->right);
           }
           q.pop();
        }
        }
        return root;
    }
};