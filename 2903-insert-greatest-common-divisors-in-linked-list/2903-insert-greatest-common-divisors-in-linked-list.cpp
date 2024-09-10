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
// int gcd(int a,int b){
//     if(b==0) return a;
//     return gcd(b,a%b);
// }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head==NULL||head->next==NULL)  return head;
         ListNode* prev=head;
        ListNode* cur=head->next;
       

        while(cur){
            ListNode* temp = new ListNode(gcd(prev->val,cur->val));
           // cur=cur->next;
            prev->next=temp;
            temp->next=cur;
            prev=cur;
            cur=prev->next;
        }
        return head;
    }
};