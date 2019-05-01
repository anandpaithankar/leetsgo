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
    ListNode* partition(ListNode* head, int x) {
        ListNode beforeHead(0);
        ListNode *before = &beforeHead;
        ListNode afterHead(0);
        ListNode *after = &afterHead;
        
        ListNode *current = head;
        while(current) {
            if (current->val < x) {
                before->next = current;
                before = before->next;
            } else {
                after->next = current;
                after = after->next;
            }
            
            current = current->next;
        }
        
        after->next = nullptr;
        before->next = afterHead.next;
        return beforeHead.next;
    }
    
};