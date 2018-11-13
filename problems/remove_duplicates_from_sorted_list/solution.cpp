/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        std::unordered_set<int> s;
        
        ListNode *prev = nullptr;
        ListNode *current = head;
        
        while (current)
        {
            if (s.count(current->val))
            {
                if (current->next)
                {
                    ListNode *next = current->next;
                    current->val = next->val;
                    current->next = next->next;

                    delete next;
                    next = nullptr;
                }
                else
                {
                    // delete current node as we have reached end of the list.
                    delete current;
                    prev->next = current = nullptr;
                }
            }
            else
            {
                s.insert(current->val);
                prev = current;
                current = current->next;
            }
        }
        
        return head;        
    }
};