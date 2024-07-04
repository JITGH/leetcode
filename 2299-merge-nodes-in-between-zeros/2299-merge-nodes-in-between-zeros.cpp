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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head->next;
        ListNode* prev=temp;
        while(prev){
            int sum=0;
            while(prev->val!=0){
            sum=sum+prev->val;
            prev=prev->next;
        }
        temp->val=sum;
        
        prev=prev->next;

        temp->next=prev;
        temp=temp->next;
        
        }
        return head->next;
        
    }
};