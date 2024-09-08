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
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k);
        int size=0;
        ListNode* cur=head;
        while(cur!=NULL){
            size++;
            cur=cur->next;
        }
        int splitsize=size/k;
        int extra=size%k;
        cur=head;
        ListNode*prev=cur;
        for(int i=0;i<k;i++){
            ListNode* node=cur;
            int cursize=splitsize;
            if(extra>0){
                extra--;
                cursize++;
            }

            int j=0;
            while(j<cursize){
                prev=cur;
                if(cur!=NULL){
                    cur=cur->next;
                }
                j++;
            }

            if(prev!=NULL){
                prev->next=NULL;
            }
            ans[i]=node;
        }
        return ans;
    }
};