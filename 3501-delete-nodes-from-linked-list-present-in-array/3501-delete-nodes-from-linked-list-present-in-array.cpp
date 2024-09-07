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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int>st(nums.begin(),nums.end());
        ListNode* dum = new ListNode(0, head);
        ListNode* cur = dum;
        
        while (cur->next != NULL) {
            if (st.find(cur->next->val) !=st.end()) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        
        //ListNode* ans = dum->next;
       // delete dum;
        return dum->next;
    }
};