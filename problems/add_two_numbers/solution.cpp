/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode{0};
        ListNode* p = dummy;
        int carry = 0;
        while (l1 || l2) {
            int digit1 = l1 ? l1->val : 0;
            int digit2 = l2 ? l2->val : 0;
            int sum = digit1+digit2+carry;
            int digit = sum % 10;
            carry = sum / 10;
            p->next = new ListNode{digit};
            p = p->next;
            if (l1) l1=l1->next;
            if (l2) l2=l2->next;
        }
        
        if (carry > 0) {
            p->next = new ListNode{carry};
        }
        
        return dummy->next;
        
    }
};