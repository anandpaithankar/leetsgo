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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *current = head;
        bool isDuplicate = false;
        
        while(current != nullptr)
        {
            ListNode *runner = current->next;
            while (runner != nullptr && runner->val == current->val)
            {
                isDuplicate = true;
                current->next = runner->next;
                delete runner;
                runner = current->next;
            }
            
            if (isDuplicate)
            {
                isDuplicate = false;
                if (prev == nullptr)
                {
                    ListNode *t = head->next;
                    delete current;
                    head = t;
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