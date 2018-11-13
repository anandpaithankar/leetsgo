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
    ListNode* removeElements(ListNode* head, int val) {
        
        if (head == nullptr)
            return head;
        
        ListNode *prev = nullptr;
        ListNode *current = head;
        
        while (current != nullptr)
        {
            if (current->val == val)
            {
                if (prev == nullptr)
                {
                    head = current->next;
                    delete current;
                    current = head;
                }
                else
                {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        return head;        
    }
};