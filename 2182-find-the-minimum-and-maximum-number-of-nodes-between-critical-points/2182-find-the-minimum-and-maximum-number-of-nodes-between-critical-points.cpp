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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
         vector<int>result={-1,-1};
        ListNode* prev=head;
        ListNode* curr=head->next;
        int mind=INT_MAX;
        int ci=1;
        int currentcritical=0;
        int previouscritical=0;

        while(curr->next!=NULL){
            if((curr->val>prev->val && curr->val>curr->next->val)||
            (
                curr->val<prev->val && curr->val<curr->next->val
            )){
            if (previouscritical==0)
            {
               previouscritical=ci;
               currentcritical=ci;
            }else
            {
                mind=min(mind,ci-previouscritical);
                previouscritical=ci;
            } 
        }
        
        ci++;
        prev=curr;
        curr=curr->next;
        }
        if(mind!=INT_MAX){
            int maxd=previouscritical-currentcritical;
            result={mind,maxd};
        }
        return result
    }
};